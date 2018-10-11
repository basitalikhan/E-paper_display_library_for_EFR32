/*
 * GxGDEP015OC1.c
 *
 *  Created on: 28-Sep-2018
 *      Author: UTF-Labs-2
 */

// class GxGDEP015OC1 : Display class for GDEP015OC1 e-Paper from Dalian Good Display Co., Ltd.: www.good-display.com

// Library: https://github.com/ZinggJM/GxEPD

#include "GxGDEP015OC1.h"

//#define DISABLE_DIAGNOSTIC_OUTPUT


#include "em_gpio.h"
#include "ustimer.h"
#include "em_usart.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include "stddef.h"
#include <stdint.h>
#include "stdbool.h"


// Pin level definition
#define LOW             0
#define HIGH            1

int rotation1;


// Partial Update Delay, may have an influence on degradation
#define GxGDEP015OC1_PU_DELAY 300

const uint16_t power_on_time = 80; // ms, e.g. 73508us
const uint16_t power_off_time = 80; // ms, e.g. 68982us
const uint16_t full_refresh_time = 1200; // ms, e.g. 1113273us
const uint16_t partial_refresh_time = 300; // ms, e.g. 290867us


uint16_t gx_uint16_min(uint16_t a, uint16_t b) {return (a < b ? a : b);};
uint16_t gx_uint16_max(uint16_t a, uint16_t b) {return (a > b ? a : b);};


void delay(unsigned int delaytime) {
	delaytime = delaytime * 1000;
	USTIMER_Delay(delaytime);
}

void WaitUntilIdle() {
	while(GPIO_PinInGet(gpioPortD, 10) == HIGH) {      //0: busy, 1: idle
		//printf("Check -4\n");
	delay(50);
  }
}

void spi_tx(uint8_t byt) {
  while( !(USART2->STATUS & (1 << 6)) ); // wait for tx buffer to empty
  USART2->TXDATA = byt;
  while (!(USART2->STATUS & USART_STATUS_TXC)) ; // Waiting for transmission of last byte
}

void EPD_Reset() {
  GPIO_PinModeSet(gpioPortD, 9, gpioModePushPull, 0);
  delay(200);
  GPIO_PinModeSet(gpioPortD, 9, gpioModePushPull, 1);
  delay(200);
}


void EPD_SendCommand(uint8_t command) {
  GPIO_PinModeSet(gpioPortD, 8, gpioModePushPull, 0);
  EpdSpiTransferCallback(command);
}

void EpdSpiTransferCallback(uint8_t data1) {
	GPIO_PinModeSet(gpioPortA, 9, gpioModePushPull, 0);
	spi_tx(data1);
    GPIO_PinModeSet(gpioPortA, 9, gpioModePushPull, 1);
}

/**
 *  @brief: basic function for sending data
 */
void EPD_SendData(uint8_t data) {
  GPIO_PinModeSet(gpioPortD, 8, gpioModePushPull, 1);
  EpdSpiTransferCallback(data);
}


//Swap function definition
void swap(int16_t *a, int16_t *b)
{
   int16_t t;

    t = *b;
   *b = *a;
   *a = t;
}

const uint8_t LUTDefault_full[] =
{
  0x32,  // command
  0x50, 0xAA, 0x55, 0xAA, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const uint8_t LUTDefault_part[] =
{
  0x32,	// command
  0x10, 0x18, 0x18, 0x08, 0x18, 0x18, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0x14, 0x44, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const uint8_t GDOControl[] = {0x01, (GxGDEP015OC1_Y_PIXELS - 1) % 256, (GxGDEP015OC1_Y_PIXELS - 1) / 256, 0x00}; //for 1.54inch
const uint8_t softstart[] = {0x0c, 0xd7, 0xd6, 0x9d};
const uint8_t VCOMVol[] = {0x2c, 0x9b}; // VCOM 7c
const uint8_t DummyLine[] = {0x3a, 0x1a}; // 4 dummy line per gate
const uint8_t Gatetime[] = {0x3b, 0x08}; // 2us per line


void GxGDEP015OC1_drawPixel(int16_t x, int16_t y, uint16_t color)
{
  //if ((x < 0) || (x >= width()) || (y < 0) || (y >= height())) return;

	if ((x < 0) || (x >= 200) || (y < 0) || (y >= 200)) return;

  // check rotation1, move pixel around if necessary
  //switch (getrotation1())
	int16_t t;
  switch (rotation1)
  {
    case 1:
      swap(x, y);
      x = GxGDEP015OC1_WIDTH - x - 1;
      break;
    case 2:
      x = GxGDEP015OC1_WIDTH - x - 1;
      y = GxGDEP015OC1_HEIGHT - y - 1;
      break;
    case 3:
      swap(x, y);
      y = GxGDEP015OC1_HEIGHT - y - 1;
      break;
    case 4:
      //swap(x, y);
    	t = x;
    	x = GxGDEP015OC1_WIDTH  - 1 - y;
    	y = t;
      break;
  }
  uint16_t i = x / 8 + y * GxGDEP015OC1_WIDTH / 8;
  if (_current_page < 1)
  {
    if (i >= sizeof(_buffer)) return;
  }
  else
  {
    y -= _current_page * GxGDEP015OC1_PAGE_HEIGHT;
    if ((y < 0) || (y >= GxGDEP015OC1_PAGE_HEIGHT)) return;
    i = x / 8 + y * GxGDEP015OC1_WIDTH / 8;
  }

  if (!color)
    _buffer[i] = (_buffer[i] | (1 << (7 - x % 8)));
  else
    _buffer[i] = (_buffer[i] & (0xFF ^ (1 << (7 - x % 8))));
}


void GxGDEP015OC1_init(uint32_t serial_diag_bitrate)
{
	serial_diag_bitrate = 0;
  if (serial_diag_bitrate > 0)
  {
	  printf("Check -2\n");
    //Serial.begin(serial_diag_bitrate);
    _diag_enabled = true;
  }

  GPIO_PinModeSet(gpioPortD, 9, gpioModePushPull, 1);	/////////////////////////////////////////////////////////////
  for(volatile long i=0; i<100000; i++);

  printf("Check -3\n");

  WaitUntilIdle();
  printf("Check -5\n");

  EPD_Reset();

  EPD_SendCommand(DRIVER_OUTPUT_CONTROL);
  EPD_SendData((EPD_HEIGHT - 1) & 0xFF);
  EPD_SendData(((EPD_HEIGHT - 1) >> 8) & 0xFF);
  EPD_SendData(0x00);                     // GD = 0; SM = 0; TB = 0;
  EPD_SendCommand(BOOSTER_SOFT_START_CONTROL);
  EPD_SendData(0xD7);
  EPD_SendData(0xD6);
  EPD_SendData(0x9D);
  EPD_SendCommand(WRITE_VCOM_REGISTER);
  EPD_SendData(0xA8);                     // VCOM 7C
  EPD_SendCommand(SET_DUMMY_LINE_PERIOD);
  EPD_SendData(0x1A);                     // 4 dummy lines per gate
  EPD_SendCommand(SET_GATE_TIME);
  EPD_SendData(0x08);                     // 2us per line
  EPD_SendCommand(DATA_ENTRY_MODE_SETTING);
  EPD_SendData(0x03);                     // X increment; Y increment

  GxGDEP015OC1_fillScreen(GxEPD_WHITE);
  printf("Check -7\n");
  _current_page = -1;
  _using_partial_mode = false;
}

void GxGDEP015OC1_fillScreen(uint16_t color)
{
	//printf("Check -6\n");
  uint8_t data = (color == GxEPD_BLACK) ? 0xFF : 0x00;
  for (uint16_t x = 0; x < sizeof(_buffer); x++)
  {
    _buffer[x] = data;
  }
}

void update(void)
{
  if (_current_page != -1) return;
  _using_partial_mode = false;
  _Init_Full(0x03);
  _writeCommand(0x24);
  for (uint16_t y = 0; y < GxGDEP015OC1_HEIGHT; y++)
  {
    for (uint16_t x = 0; x < GxGDEP015OC1_WIDTH / 8; x++)
    {
      uint16_t idx = y * (GxGDEP015OC1_WIDTH / 8) + x;
      uint8_t data = (idx < sizeof(_buffer)) ? _buffer[idx] : 0x00;
      _writeData(~data);
    }
  }
  _Update_Full();
  _PowerOff();
}

void  GxGDEP015OC1_drawBitmap1(const uint8_t *bitmap, uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color, int16_t mode)
{
	mode = bm_normal;
  if (mode & bm_default) mode |= bm_flip_x | bm_invert;
  GxEPD_drawBitmapBM(bitmap, x, y, w, h, color, mode);
}

void GxGDEP015OC1_drawBitmap2(const uint8_t *bitmap, uint32_t size, int16_t mode)
{
	//mode = bm_normal;
  if (_current_page != -1) return;
  // example bitmaps are made for y-decrement, x-increment, for origin on opposite corner
  // bm_flip_x for normal display (bm_flip_y would be rotated)
  if (mode & bm_default) mode |= bm_flip_x;
  uint8_t ram_entry_mode = 0x03; // y-increment, x-increment for normal mode
  if ((mode & bm_flip_y) && (mode & bm_flip_x)) ram_entry_mode = 0x00; // y-decrement, x-decrement
  else if (mode & bm_flip_y) ram_entry_mode = 0x01; // y-decrement, x-increment
  else if (mode & bm_flip_x) ram_entry_mode = 0x02; // y-increment, x-decrement
  if (mode & bm_partial_update)
  {
    _using_partial_mode = true; // remember
    _Init_Part(ram_entry_mode);
    _writeCommand(0x24);
    for (uint32_t i = 0; i < GxGDEP015OC1_BUFFER_SIZE; i++)
    {
      uint8_t data = 0xFF; // white is 0xFF on device
      if (i < size)
      {
//#if defined(__AVR) || defined(ESP8266) || defined(ESP32)	//////////////////////////////////////
//        data = pgm_read_byte(&bitmap[i]);//////////////////////////////////////////////
//#else///////////////////////////////////////////////////////////////////
        data = bitmap[i];
//#endif/////////////////////////////////////////////////////////////////
        if (mode & bm_invert) data = ~data;
      }
      _writeData(data);
    }
    _Update_Part();
    delay(GxGDEP015OC1_PU_DELAY);
    // update erase buffer
    _writeCommand(0x24);
    for (uint32_t i = 0; i < GxGDEP015OC1_BUFFER_SIZE; i++)
    {
      uint8_t data = 0xFF; // white is 0xFF on device
      if (i < size)
      {
        data = bitmap[i];
        if (mode & bm_invert) data = ~data;
      }
      _writeData(data);
    }
    delay(GxGDEP015OC1_PU_DELAY);
    _PowerOff();
  }
  else
  {
    _using_partial_mode = false; // remember
    _Init_Full(ram_entry_mode);
    _writeCommand(0x24);
    for (uint32_t i = 0; i < GxGDEP015OC1_BUFFER_SIZE; i++)
    {
      uint8_t data = 0xFF; // white is 0xFF on device
      if (i < size)
      {
        data = bitmap[i];
        if (mode & bm_invert) data = ~data;
      }
      _writeData(data);
    }
    _Update_Full();
    _PowerOff();
  }
}

void eraseDisplay(bool using_partial_update)
{
	using_partial_update = false;
  if (_current_page != -1) return;
  if (using_partial_update)
  {
    _using_partial_mode = true; // remember
    _Init_Part(0x01);
    _writeCommand(0x24);
    for (uint32_t i = 0; i < GxGDEP015OC1_BUFFER_SIZE; i++)
    {
      _writeData(0xFF);
    }
    _Update_Part();
    delay(GxGDEP015OC1_PU_DELAY);
    // update erase buffer
    _writeCommand(0x24);
    for (uint32_t i = 0; i < GxGDEP015OC1_BUFFER_SIZE; i++)
    {
      _writeData(0xFF);
    }
    delay(GxGDEP015OC1_PU_DELAY);
  }
  else
  {
    _using_partial_mode = false; // remember
    _Init_Full(0x01);
    _writeCommand(0x24);
    for (uint32_t i = 0; i < GxGDEP015OC1_BUFFER_SIZE; i++)
    {
      _writeData(0xFF);
    }
    _Update_Full();
    _PowerOff();
  }
}

void updateWindow(uint16_t x, uint16_t y, uint16_t w, uint16_t h)
{
	bool using_rotation = true;
  if (_current_page != -1) return;
  if (using_rotation) _rotate(x, y, w, h);
  if (x >= GxGDEP015OC1_WIDTH) return;
  if (y >= GxGDEP015OC1_HEIGHT) return;
  uint16_t xe = gx_uint16_min(GxGDEP015OC1_WIDTH, x + w) - 1;
  uint16_t ye = gx_uint16_min(GxGDEP015OC1_HEIGHT, y + h) - 1;
  uint16_t xs_d8 = x / 8;
  uint16_t xe_d8 = xe / 8;
  _Init_Part(0x03);
  _SetRamArea(xs_d8, xe_d8, y % 256, y / 256, ye % 256, ye / 256); // X-source area,Y-gate area
  _SetRamPointer(xs_d8, y % 256, y / 256); // set ram
  WaitUntilIdle();
  _writeCommand(0x24);
  for (int16_t y1 = y; y1 <= ye; y1++)
  {
    for (int16_t x1 = xs_d8; x1 <= xe_d8; x1++)
    {
      uint16_t idx = y1 * (GxGDEP015OC1_WIDTH / 8) + x1;
      uint8_t data = (idx < sizeof(_buffer)) ? _buffer[idx] : 0x00;
      _writeData(~data);
    }
  }
  _Update_Part();
  delay(GxGDEP015OC1_PU_DELAY);
  // update erase buffer
  _SetRamArea(xs_d8, xe_d8, y % 256, y / 256, ye % 256, ye / 256); // X-source area,Y-gate area
  _SetRamPointer(xs_d8, y % 256, y / 256); // set ram
  WaitUntilIdle();
  _writeCommand(0x24);
  for (int16_t y1 = y; y1 <= ye; y1++)
  {
    for (int16_t x1 = xs_d8; x1 <= xe_d8; x1++)
    {
      uint16_t idx = y1 * (GxGDEP015OC1_WIDTH / 8) + x1;
      uint8_t data = (idx < sizeof(_buffer)) ? _buffer[idx] : 0x00;
      _writeData(~data);
    }
  }
  delay(GxGDEP015OC1_PU_DELAY);
}

void _writeToWindow(uint16_t xs, uint16_t ys, uint16_t xd, uint16_t yd, uint16_t w, uint16_t h)
{
  //Serial.printf("_writeToWindow(%d, %d, %d, %d, %d, %d)\n", xs, ys, xd, yd, w, h);
  // the screen limits are the hard limits
  if (xs >= GxGDEP015OC1_WIDTH) return;
  if (ys >= GxGDEP015OC1_HEIGHT) return;
  if (xd >= GxGDEP015OC1_WIDTH) return;
  if (yd >= GxGDEP015OC1_HEIGHT) return;
  w = gx_uint16_min(w, GxGDEP015OC1_WIDTH - xs);
  w = gx_uint16_min(w, GxGDEP015OC1_WIDTH - xd);
  h = gx_uint16_min(h, GxGDEP015OC1_HEIGHT - ys);
  h = gx_uint16_min(h, GxGDEP015OC1_HEIGHT - yd);
  uint16_t xds_d8 = xd / 8;
  uint16_t xde_d8 = (xd + w - 1) / 8;
  uint16_t yde = yd + h - 1;
  // soft limits, must send as many bytes as set by _SetRamArea
  uint16_t xse_d8 = xs / 8 + xde_d8 - xds_d8;
  uint16_t yse = ys + h - 1;
  _SetRamArea(xds_d8, xde_d8, yd % 256, yd / 256, yde % 256, yde / 256); // X-source area,Y-gate area
  _SetRamPointer(xds_d8, yd % 256, yd / 256); // set ram
  WaitUntilIdle();
  _writeCommand(0x24);
  for (int16_t y1 = ys; y1 <= yse; y1++)
  {
    for (int16_t x1 = xs / 8; x1 <= xse_d8; x1++)
    {
      uint16_t idx = y1 * (GxGDEP015OC1_WIDTH / 8) + x1;
      uint8_t data = (idx < sizeof(_buffer)) ? _buffer[idx] : 0x00;
      _writeData(~data);
    }
  }
}

void updateToWindow(uint16_t xs, uint16_t ys, uint16_t xd, uint16_t yd, uint16_t w, uint16_t h, bool using_rotation)
{
	using_rotation = true;
  if (using_rotation)
  {
    //switch (getRotation())
	  switch (rotation1)
    {
      case 1:
        swap(xs, ys);
        swap(xd, yd);
        swap(w, h);
        xs = GxGDEP015OC1_WIDTH - xs - w - 1;
        xd = GxGDEP015OC1_WIDTH - xd - w - 1;
        break;
      case 2:
        xs = GxGDEP015OC1_WIDTH - xs - w - 1;
        ys = GxGDEP015OC1_HEIGHT - ys - h - 1;
        xd = GxGDEP015OC1_WIDTH - xd - w - 1;
        yd = GxGDEP015OC1_HEIGHT - yd - h - 1;
        break;
      case 3:
        swap(xs, ys);
        swap(xd, yd);
        swap(w, h);
        ys = GxGDEP015OC1_HEIGHT - ys  - h - 1;
        yd = GxGDEP015OC1_HEIGHT - yd  - h - 1;
        break;
    }
  }
  _Init_Part(0x03);
  _writeToWindow(xs, ys, xd, yd, w, h);
  _Update_Part();
  delay(GxGDEP015OC1_PU_DELAY);
  // update erase buffer
  _writeToWindow(xs, ys, xd, yd, w, h);
  delay(GxGDEP015OC1_PU_DELAY);
}

void powerDown()
{
  _using_partial_mode = false;
  _PowerOff();
}

void _writeCommandTransaction(uint8_t c)
{
  GPIO_PinModeSet(gpioPortD, 8, gpioModePushPull, 0);  //dc pin
  GPIO_PinModeSet(gpioPortA, 9, gpioModePushPull, 0);  //cs pin
  //printf("Check -14\n");
  spi_tx(c);
  GPIO_PinModeSet(gpioPortA, 9, gpioModePushPull, 1);  //cs pin
  GPIO_PinModeSet(gpioPortD, 8, gpioModePushPull, 1);  //dc pin
}

void _writeCommand(uint8_t command)
{
  //printf("Check -13\n");
  WaitUntilIdle();
  _writeCommandTransaction(command);
}

void _writeDataTransaction(uint8_t d)
{
	//printf("Check -17\n");
  GPIO_PinModeSet(gpioPortA, 9, gpioModePushPull, 0);  //cs pin
  spi_tx(d);
  GPIO_PinModeSet(gpioPortA, 9, gpioModePushPull, 1);  //cs pin
}

void _writeData(uint8_t data)
{
	//printf("Check -16\n");
  _writeDataTransaction(data);
}

void _startTransaction()
{
  GPIO_PinModeSet(gpioPortA, 9, gpioModePushPull, 0);  //cs pin
}

void _endTransaction()
{
  GPIO_PinModeSet(gpioPortA, 9, gpioModePushPull, 1);  //cs pin
}

void _writeCommandData(const uint8_t* pCommandData, uint8_t datalen)
{
  WaitUntilIdle();
  _startTransaction();
  _writeCommand(*pCommandData++);
  for (uint8_t i = 0; i < datalen - 1; i++)  // sub the command
  {
    _writeData(*pCommandData++);
  }
  _endTransaction();

}

void _setRamDataEntryMode(uint8_t em)
{
  const uint16_t xPixelsPar = GxGDEP015OC1_X_PIXELS - 1;
  const uint16_t yPixelsPar = GxGDEP015OC1_Y_PIXELS - 1;
  em = gx_uint16_min(em, 0x03);
  _writeCommand(0x11);
  _writeData(em);
  switch (em)
  {
    case 0x00: // x decrease, y decrease
      _SetRamArea(xPixelsPar / 8, 0x00, yPixelsPar % 256, yPixelsPar / 256, 0x00, 0x00);  // X-source area,Y-gate area
      _SetRamPointer(xPixelsPar / 8, yPixelsPar % 256, yPixelsPar / 256); // set ram
      break;
    case 0x01: // x increase, y decrease : as in demo code
      _SetRamArea(0x00, xPixelsPar / 8, yPixelsPar % 256, yPixelsPar / 256, 0x00, 0x00);  // X-source area,Y-gate area
      _SetRamPointer(0x00, yPixelsPar % 256, yPixelsPar / 256); // set ram
      break;
    case 0x02: // x decrease, y increase
      _SetRamArea(xPixelsPar / 8, 0x00, 0x00, 0x00, yPixelsPar % 256, yPixelsPar / 256);  // X-source area,Y-gate area
      _SetRamPointer(xPixelsPar / 8, 0x00, 0x00); // set ram
      break;
    case 0x03: // x increase, y increase : normal mode
      _SetRamArea(0x00, xPixelsPar / 8, 0x00, 0x00, yPixelsPar % 256, yPixelsPar / 256);  // X-source area,Y-gate area
      _SetRamPointer(0x00, 0x00, 0x00); // set ram
      break;
  }
}

void _SetRamArea(uint8_t Xstart, uint8_t Xend, uint8_t Ystart, uint8_t Ystart1, uint8_t Yend, uint8_t Yend1)
{
  _writeCommand(0x44);
  _writeData(Xstart);
  _writeData(Xend);
  _writeCommand(0x45);
  _writeData(Ystart);
  _writeData(Ystart1);
  _writeData(Yend);
  _writeData(Yend1);
}

void _SetRamPointer(uint8_t addrX, uint8_t addrY, uint8_t addrY1)
{
  _writeCommand(0x4e);
  _writeData(addrX);
  _writeCommand(0x4f);
  _writeData(addrY);
  _writeData(addrY1);
}

void _PowerOn(void)
{
  _writeCommand(0x22);
  _writeData(0xc0);
  _writeCommand(0x20);
  //_waitWhileBusy("_PowerOn", power_on_time);
  WaitUntilIdle();
}

void _PowerOff(void)
{
  _writeCommand(0x22);
  _writeData(0xc3);
  _writeCommand(0x20);
  //_waitWhileBusy("_PowerOff", power_off_time);
  WaitUntilIdle();
}

void _InitDisplay(uint8_t em)
{
  _writeCommandData(GDOControl, sizeof(GDOControl));  // Pannel configuration, Gate selection
  _writeCommandData(softstart, sizeof(softstart));  // X decrease, Y decrease
  _writeCommandData(VCOMVol, sizeof(VCOMVol));    // VCOM setting
  _writeCommandData(DummyLine, sizeof(DummyLine));  // dummy line per gate
  _writeCommandData(Gatetime, sizeof(Gatetime));    // Gate time setting
  _setRamDataEntryMode(em);
}

void _Init_Full(uint8_t em)
{
  _InitDisplay(em);
  _writeCommandData(LUTDefault_full, sizeof(LUTDefault_full));
  _PowerOn();
}

void _Init_Part(uint8_t em)
{
  _InitDisplay(em);
  _writeCommandData(LUTDefault_part, sizeof(LUTDefault_part));
  _PowerOn();
}

void _Update_Full(void)
{
  //printf("Check -18\n");
  _writeCommand(0x22);
  _writeData(0xc4);
  _writeCommand(0x20);
  //printf("Check -19\n");
  WaitUntilIdle();
  _writeCommand(0xff);
  //printf("Check -20\n");
}

void _Update_Part(void)
{
  _writeCommand(0x22);
  _writeData(0x04);
  _writeCommand(0x20);
  WaitUntilIdle();
  _writeCommand(0xff);
}

void drawPaged1(void (*drawCallback)(void))
{
  if (_current_page != -1) return;
  _using_partial_mode = false;
  _Init_Full(0x03);
  _writeCommand(0x24);
  for (_current_page = 0; _current_page < GxGDEP015OC1_PAGES; _current_page++)
  {
    GxGDEP015OC1_fillScreen(GxEPD_WHITE);
    drawCallback();
    for (int16_t y1 = 0; y1 < GxGDEP015OC1_PAGE_HEIGHT; y1++)
    {
      for (int16_t x1 = 0; x1 < GxGDEP015OC1_WIDTH / 8; x1++)
      {
        uint16_t idx = y1 * (GxGDEP015OC1_WIDTH / 8) + x1;
        uint8_t data = (idx < sizeof(_buffer)) ? _buffer[idx] : 0x00;
        _writeData(~data);
      }
    }
  }
  _current_page = -1;
  _Update_Full();
  _PowerOff();
}

void drawPaged2(void (*drawCallback)(uint32_t), uint32_t p)
{
  if (_current_page != -1) return;
  _using_partial_mode = false;
  _Init_Full(0x03);
  _writeCommand(0x24);
  for (_current_page = 0; _current_page < GxGDEP015OC1_PAGES; _current_page++)
  {
    GxGDEP015OC1_fillScreen(GxEPD_WHITE);
    drawCallback(p);
    for (int16_t y1 = 0; y1 < GxGDEP015OC1_PAGE_HEIGHT; y1++)
    {
      for (int16_t x1 = 0; x1 < GxGDEP015OC1_WIDTH / 8; x1++)
      {
        uint16_t idx = y1 * (GxGDEP015OC1_WIDTH / 8) + x1;
        uint8_t data = (idx < sizeof(_buffer)) ? _buffer[idx] : 0x00;
        _writeData(~data);
      }
    }
  }
  _current_page = -1;
  _Update_Full();
  _PowerOff();
}

void drawPaged3(void (*drawCallback)(const void*), const void* p)
{
  if (_current_page != -1) return;
  _using_partial_mode = false;
  _Init_Full(0x03);
  _writeCommand(0x24);
  for (_current_page = 0; _current_page < GxGDEP015OC1_PAGES; _current_page++)
  {
    GxGDEP015OC1_fillScreen(GxEPD_WHITE);
    drawCallback(p);
    for (int16_t y1 = 0; y1 < GxGDEP015OC1_PAGE_HEIGHT; y1++)
    {
      for (int16_t x1 = 0; x1 < GxGDEP015OC1_WIDTH / 8; x1++)
      {
        uint16_t idx = y1 * (GxGDEP015OC1_WIDTH / 8) + x1;
        uint8_t data = (idx < sizeof(_buffer)) ? _buffer[idx] : 0x00;
        _writeData(~data);
      }
    }
  }
  _current_page = -1;
  _Update_Full();
  _PowerOff();
}

void drawPaged4(void (*drawCallback)(const void*, const void*), const void* p1, const void* p2)
{
  if (_current_page != -1) return;
  _using_partial_mode = false;
  _Init_Full(0x03);
  _writeCommand(0x24);
  for (_current_page = 0; _current_page < GxGDEP015OC1_PAGES; _current_page++)
  {
    GxGDEP015OC1_fillScreen(GxEPD_WHITE);
    drawCallback(p1, p2);
    for (int16_t y1 = 0; y1 < GxGDEP015OC1_PAGE_HEIGHT; y1++)
    {
      for (int16_t x1 = 0; x1 < GxGDEP015OC1_WIDTH / 8; x1++)
      {
        uint16_t idx = y1 * (GxGDEP015OC1_WIDTH / 8) + x1;
        uint8_t data = (idx < sizeof(_buffer)) ? _buffer[idx] : 0x00;
        _writeData(~data);
      }
    }
  }
  _current_page = -1;
  _Update_Full();
  _PowerOff();
}

void _rotate(uint16_t x, uint16_t y, uint16_t w, uint16_t h)
{
  //switch (getRotation())
	switch (rotation1)
  {
    case 1:
      swap(x, y);
      swap(w, h);
      x = GxGDEP015OC1_WIDTH - x - w - 1;
      break;
    case 2:
      x = GxGDEP015OC1_WIDTH - x - w - 1;
      y = GxGDEP015OC1_HEIGHT - y - h - 1;
      break;
    case 3:
      swap(x, y);
      swap(w, h);
      y = GxGDEP015OC1_HEIGHT - y - h - 1;
      break;
  }
}


void drawPagedToWindow1(void (*drawCallback)(void), uint16_t x, uint16_t y, uint16_t w, uint16_t h)
{
  if (_current_page != -1) return;
  _rotate(x, y, w, h);
  if (!_using_partial_mode)
  {
    eraseDisplay(false);
    eraseDisplay(true);
  }
  _using_partial_mode = true;
  _Init_Part(0x03);
  for (_current_page = 0; _current_page < GxGDEP015OC1_PAGES; _current_page++)
  {
    uint16_t yds = gx_uint16_max(y, _current_page * GxGDEP015OC1_PAGE_HEIGHT);
    uint16_t yde = gx_uint16_min(y + h, (_current_page + 1) * GxGDEP015OC1_PAGE_HEIGHT);
    if (yde > yds)
    {
      GxGDEP015OC1_fillScreen(GxEPD_WHITE);
      drawCallback();
      uint16_t ys = yds % GxGDEP015OC1_PAGE_HEIGHT;
      _writeToWindow(x, ys, x, yds, w, yde - yds);
    }
  }
  _Update_Part();
  delay(GxGDEP015OC1_PU_DELAY);
  // update erase buffer
  for (_current_page = 0; _current_page < GxGDEP015OC1_PAGES; _current_page++)
  {
    uint16_t yds = gx_uint16_max(y, _current_page * GxGDEP015OC1_PAGE_HEIGHT);
    uint16_t yde = gx_uint16_min(y + h, (_current_page + 1) * GxGDEP015OC1_PAGE_HEIGHT);
    if (yde > yds)
    {
      GxGDEP015OC1_fillScreen(GxEPD_WHITE);
      drawCallback();
      uint16_t ys = yds % GxGDEP015OC1_PAGE_HEIGHT;
      _writeToWindow(x, ys, x, yds, w, yde - yds);
    }
  }
  delay(GxGDEP015OC1_PU_DELAY);
  _current_page = -1;
  _PowerOff();
}


void drawPagedToWindow2(void (*drawCallback)(uint32_t), uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint32_t p)
{
  if (_current_page != -1) return;
  _rotate(x, y, w, h);
  if (!_using_partial_mode)
  {
    eraseDisplay(false);
    eraseDisplay(true);
  }
  _using_partial_mode = true;
  _Init_Part(0x03);
  for (_current_page = 0; _current_page < GxGDEP015OC1_PAGES; _current_page++)
  {
    uint16_t yds = gx_uint16_max(y, _current_page * GxGDEP015OC1_PAGE_HEIGHT);
    uint16_t yde = gx_uint16_min(y + h, (_current_page + 1) * GxGDEP015OC1_PAGE_HEIGHT);
    if (yde > yds)
    {
      GxGDEP015OC1_fillScreen(GxEPD_WHITE);
      drawCallback(p);
      uint16_t ys = yds % GxGDEP015OC1_PAGE_HEIGHT;
      _writeToWindow(x, ys, x, yds, w, yde - yds);
    }
  }
  _Update_Part();
  delay(GxGDEP015OC1_PU_DELAY);
  // update erase buffer
  for (_current_page = 0; _current_page < GxGDEP015OC1_PAGES; _current_page++)
  {
    uint16_t yds = gx_uint16_max(y, _current_page * GxGDEP015OC1_PAGE_HEIGHT);
    uint16_t yde = gx_uint16_min(y + h, (_current_page + 1) * GxGDEP015OC1_PAGE_HEIGHT);
    if (yde > yds)
    {
      GxGDEP015OC1_fillScreen(GxEPD_WHITE);
      drawCallback(p);
      uint16_t ys = yds % GxGDEP015OC1_PAGE_HEIGHT;
      _writeToWindow(x, ys, x, yds, w, yde - yds);
    }
  }
  delay(GxGDEP015OC1_PU_DELAY);
  _current_page = -1;
  _PowerOff();
}

void drawPagedToWindow3(void (*drawCallback)(const void*), uint16_t x, uint16_t y, uint16_t w, uint16_t h, const void* p)
{
  if (_current_page != -1) return;
  _rotate(x, y, w, h);
  if (!_using_partial_mode)
  {
    eraseDisplay(false);
    eraseDisplay(true);
  }
  _using_partial_mode = true;
  _Init_Part(0x03);
  for (_current_page = 0; _current_page < GxGDEP015OC1_PAGES; _current_page++)
  {
    uint16_t yds = gx_uint16_max(y, _current_page * GxGDEP015OC1_PAGE_HEIGHT);
    uint16_t yde = gx_uint16_min(y + h, (_current_page + 1) * GxGDEP015OC1_PAGE_HEIGHT);
    if (yde > yds)
    {
      GxGDEP015OC1_fillScreen(GxEPD_WHITE);
      drawCallback(p);
      uint16_t ys = yds % GxGDEP015OC1_PAGE_HEIGHT;
      _writeToWindow(x, ys, x, yds, w, yde - yds);
    }
  }
  _Update_Part();
  delay(GxGDEP015OC1_PU_DELAY);
  // update erase buffer
  for (_current_page = 0; _current_page < GxGDEP015OC1_PAGES; _current_page++)
  {
    uint16_t yds = gx_uint16_max(y, _current_page * GxGDEP015OC1_PAGE_HEIGHT);
    uint16_t yde = gx_uint16_min(y + h, (_current_page + 1) * GxGDEP015OC1_PAGE_HEIGHT);
    if (yde > yds)
    {
      GxGDEP015OC1_fillScreen(GxEPD_WHITE);
      drawCallback(p);
      uint16_t ys = yds % GxGDEP015OC1_PAGE_HEIGHT;
      _writeToWindow(x, ys, x, yds, w, yde - yds);
    }
  }
  delay(GxGDEP015OC1_PU_DELAY);
  _current_page = -1;
  _PowerOff();
}

void drawPagedToWindow4(void (*drawCallback)(const void*, const void*), uint16_t x, uint16_t y, uint16_t w, uint16_t h, const void* p1, const void* p2)
{
  if (_current_page != -1) return;
  _rotate(x, y, w, h);
  if (!_using_partial_mode)
  {
    eraseDisplay(false);
    eraseDisplay(true);
  }
  _using_partial_mode = true;
  _Init_Part(0x03);
  for (_current_page = 0; _current_page < GxGDEP015OC1_PAGES; _current_page++)
  {
    uint16_t yds = gx_uint16_max(y, _current_page * GxGDEP015OC1_PAGE_HEIGHT);
    uint16_t yde = gx_uint16_min(y + h, (_current_page + 1) * GxGDEP015OC1_PAGE_HEIGHT);
    if (yde > yds)
    {
      GxGDEP015OC1_fillScreen(GxEPD_WHITE);
      drawCallback(p1, p2);
      uint16_t ys = yds % GxGDEP015OC1_PAGE_HEIGHT;
      _writeToWindow(x, ys, x, yds, w, yde - yds);
    }
  }
  _Update_Part();
  delay(GxGDEP015OC1_PU_DELAY);
  // update erase buffer
  for (_current_page = 0; _current_page < GxGDEP015OC1_PAGES; _current_page++)
  {
    uint16_t yds = gx_uint16_max(y, _current_page * GxGDEP015OC1_PAGE_HEIGHT);
    uint16_t yde = gx_uint16_min(y + h, (_current_page + 1) * GxGDEP015OC1_PAGE_HEIGHT);
    if (yde > yds)
    {
      GxGDEP015OC1_fillScreen(GxEPD_WHITE);
      drawCallback(p1, p2);
      uint16_t ys = yds % GxGDEP015OC1_PAGE_HEIGHT;
      _writeToWindow(x, ys, x, yds, w, yde - yds);
    }
  }
  delay(GxGDEP015OC1_PU_DELAY);
  _current_page = -1;
  _PowerOff();
}

void drawCornerTest()
{
  //printf("Check -10\n");
  uint8_t em = 0x01;
  if (_current_page != -1) return;

  //printf("Check -11\n");
  _Init_Full(em);
  //printf("Check -12\n");
  _writeCommand(0x24);
  //printf("Check -15\n");
  for (uint32_t y = 0; y < GxGDEP015OC1_HEIGHT; y++)
  {
    for (uint32_t x = 0; x < GxGDEP015OC1_WIDTH / 8; x++)
    {
      uint8_t data = 0xFF;
      if ((x < 1) && (y < 8)) data = 0x00;
      if ((x > GxGDEP015OC1_WIDTH / 8 - 3) && (y < 16)) data = 0x00;
      if ((x > GxGDEP015OC1_WIDTH / 8 - 4) && (y > GxGDEP015OC1_HEIGHT - 25)) data = 0x00;
      if ((x < 4) && (y > GxGDEP015OC1_HEIGHT - 33)) data = 0x00;
      _writeData(data);
    }
  }
  //printf("Check -16\n");
  _Update_Full();
  //printf("Check -17\n");
  _PowerOff();
  //printf("Check -21\n");
}
