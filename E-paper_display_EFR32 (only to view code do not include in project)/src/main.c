#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "em_usart.h"
#include "ustimer.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include "stddef.h"
#include <stdint.h>
#include "stdbool.h"

#include "GxEPD.h"
#include "GxGDEP015OC1.h"
#include "Adafruit_GFX.h"
#include GxEPD_BitmapExamples

#include "IMG_0001.h"

#include <CarlitoBold.h>
#include <FreeSerif18pt7b.h>
#include <FreeSerifBold18pt7b.h>
#include <FreeMono12pt7b.h>
#include <FreeMonoBold12pt7b.h>
#include <FreeMono18pt7b.h>
#include <FreeMonoBold18pt7b.h>
#include <Segment7Normal18pt7b.h>
#include <FreeSans12pt7b.h>
#include <FreeSerif12pt7b.h>

#include "retargetserial.h"

//#include "i2cspm.h"
//#include "si7013.h"

#define width 200
#define height 200

int rotation1;

const char* name;
const GFXfont* f;
int FONT_WIDTH;


void delay1(unsigned int delaytime1) {
	delaytime1 = delaytime1 * 1000;
	USTIMER_Delay(delaytime1);
}

/**************************************************************************//**
 * @brief Initialize USART2
 *****************************************************************************/
void initUSART2 (void)
{
  CMU_ClockEnable(cmuClock_GPIO, true);
  CMU_ClockEnable(cmuClock_USART2, true);

  // Configure GPIO mode
  GPIO_PinModeSet(gpioPortA, 8, gpioModePushPull, 0); // US2_CLK is push pull
  GPIO_PinModeSet(gpioPortA, 9, gpioModePushPull, 1); // US2_CS is push pull
  GPIO_PinModeSet(gpioPortA, 6, gpioModePushPull, 1); // US2_TX (MOSI) is push pull
  GPIO_PinModeSet(gpioPortA, 7, gpioModeInput, 1);    // US2_RX (MISO) is input

  GPIO_PinModeSet(gpioPortD, 10, gpioModeInput, 0);    // BUSY is input
  GPIO_PinModeSet(gpioPortD, 8, gpioModePushPull, 1);    // DC is OUTPUT
  GPIO_PinModeSet(gpioPortD, 9, gpioModePushPull, 1);    // RESET is OUTPUT

  //GPIO_PinModeSet(gpioPortA, 5, gpioModePushPull, 1);    //


  // Start with default config, then modify as necessary
  USART_InitSync_TypeDef config = USART_INITSYNC_DEFAULT;
  config.master       = true;            // master mode
  config.baudrate     = 2000000;         // CLK freq is 2 MHz
  config.autoCsEnable = true;            // CS pin controlled by hardware, not firmware
  config.clockMode    = usartClockMode0; // clock idle low, sample on rising/first edge
  config.msbf         = true;            // send MSB first
  config.enable       = false;           // making sure to keep USART disabled until we've set everything up
  USART_InitSync(USART2, &config);

  // Set USART pin locations
  USART2->ROUTELOC0 = (USART_ROUTELOC0_CLKLOC_LOC1) | // US2_CLK       on location 1 = PA8 per datasheet section 6.4 = EXP Header pin 8
                      (USART_ROUTELOC0_CSLOC_LOC1)  | // US2_CS        on location 1 = PA9 per datasheet section 6.4 = EXP Header pin 10
                      (USART_ROUTELOC0_TXLOC_LOC1)  | // US2_TX (MOSI) on location 1 = PA6 per datasheet section 6.4 = EXP Header pin 4
                      (USART_ROUTELOC0_RXLOC_LOC1);   // US2_RX (MISO) on location 1 = PA7 per datasheet section 6.4 = EXP Header pin 6

  // Enable USART pins
  USART2->ROUTEPEN = USART_ROUTEPEN_CLKPEN | USART_ROUTEPEN_CSPEN | USART_ROUTEPEN_TXPEN | USART_ROUTEPEN_RXPEN;

  // Enabling TX interrupts to transfer whenever
  // there is room in the transmit buffer
  USART_IntClear(USART2, USART_IF_TXBL);

  // Enabling RX interrupts to trigger whenever
  // a new packet arrives from the slave
  USART_IntClear(USART2, USART_IF_RXDATAV);

  // Enable USART2
  USART_Enable(USART2, usartEnable);
}


void showBoat()
{
  uint16_t x = (width - 64) / 2;
  uint16_t y = 5;
  GxGDEP015OC1_fillScreen(GxEPD_WHITE);
  drawExampleBitmap2(gImage_IMG_0001, x, y, 64, 180, GxEPD_BLACK);
  update();
  delay(100);
  uint16_t forward = bm_invert | bm_flip_x;
  uint16_t reverse = bm_invert | bm_flip_x | bm_flip_y;
  for (; y + 180 + 5 <= height; y += 5)
  {
	GxGDEP015OC1_fillScreen(GxEPD_WHITE);
	drawExampleBitmap2(gImage_IMG_0001, x, y, 64, 180, GxEPD_BLACK, forward);
    updateWindow(0, 0, width, height);
    delay(100);
  }
  delay(100);
  for (; y >= 5; y -= 5)
  {
	GxGDEP015OC1_fillScreen(GxEPD_WHITE);
	drawExampleBitmap2(gImage_IMG_0001, x, y, 64, 180, GxEPD_BLACK, reverse);
    updateWindow(0, 0, width, height);
    delay(100);
  }
  update();
  delay(100);
}

 void drawExampleBitmap1(const uint8_t *bitmap, uint32_t size) // monochrome
 {
	 int16_t m = bm_default;
	 GxGDEP015OC1_drawBitmap2(bitmap, size, m);
 }

void drawExampleBitmap2(const uint8_t *bitmap, uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color)
{
	int16_t m = bm_default;
	GxGDEP015OC1_drawBitmap1(bitmap, x, y, w, h, color, m);
}

void showBitmapExample()
{
  drawExampleBitmap1(BitmapExample1, sizeof(BitmapExample1));
  delay1(1000);
  drawExampleBitmap1(BitmapExample2, sizeof(BitmapExample2));
  delay1(1000);
  GxGDEP015OC1_fillScreen(GxEPD_WHITE);
  drawExampleBitmap2(BitmapExample1, 0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK);
  update();
  delay1(1000);
  showBoat();
  delay1(1000);
}



void _print(uint16_t x_start, uint16_t y_start, const char* format, ...)
{
      // This stuff here deals with the elipsis (...) input
    char       msg[200 / FONT_WIDTH];
    va_list    args;

    va_start(args, format);
    vsnprintf(msg, sizeof(msg), format, args);
    va_end(args);

    // Get a pointer to the message
    char * string = msg;
    while (*string != 0)
    {
      drawChar(x_start, y_start, *string++, GxEPD_BLACK, GxEPD_WHITE, 1);
      x_start += FONT_WIDTH;
    }
}

void showFontCallback()
{
  name = "FreeMono12pt7b";
  f = &FreeMono12pt7b;
  GxGDEP015OC1_fillScreen(GxEPD_WHITE);
  setTextColor(GxEPD_BLACK);
  setFont(f);
  setCursor(0, 0);
  rotation1 = 0;

  FONT_WIDTH = 13;
  _print(0,16, name);
  _print(0,45," !\"#$%&'()*+,-./");

  name = "FreeMonoBold12pt7b";
  f = &FreeMonoBold12pt7b;
  setTextColor(GxEPD_BLACK);
  setFont(f);
  FONT_WIDTH = 14;
  _print(0,73, "1234567890");

  name = "FreeSans12pt7b";
  f = &FreeSans12pt7b;
  setTextColor(GxEPD_BLACK);
  setFont(f);
  FONT_WIDTH = 15;
  _print(0,105, "EFR32 Rocks!");

  name = "FreeSerif12pt7b";
  f = &FreeSerif12pt7b;
  setTextColor(GxEPD_BLACK);
  setFont(f);
  FONT_WIDTH = 15;
  _print(0,135, "EFR32 Rocks!");

  name = "Segment7Normal18pt7b";
  f = &Segment7Normal18pt7b;
  setTextColor(GxEPD_BLACK);
  setFont(f);
  FONT_WIDTH = 30;
  _print(0,185, "12345");
}


int main(void)
{
  /* Chip errata */
  CHIP_Init();

  CMU_ClockEnable(cmuClock_GPIO, true);

  /* Initialize LEUART/USART and map LF to CRLF */
    RETARGET_SerialInit();
    RETARGET_SerialCrLf(1);

  initUSART2();

  USTIMER_Init();

  GPIO_PinModeSet(gpioPortA, 5, gpioModePushPull, 1);

  printf("--------------------------BAK--------------------------\n\n");

  GxGDEP015OC1_init(115200);

  /* Infinite loop */
  while (1) {
	  rotation1 = 1;
	  showBitmapExample();
	  delay1(1000);
	  drawCornerTest();
	  delay1(500);
	  drawPaged1(showFontCallback);
	  delay1(5000);
  }
}
