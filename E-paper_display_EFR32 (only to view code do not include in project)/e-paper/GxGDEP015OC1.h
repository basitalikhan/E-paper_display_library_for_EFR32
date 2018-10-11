/*
 * GxGDEP015OC1.h
 *
 *  Created on: 28-Sep-2018
 *      Author: UTF-Labs-2
 */

#ifndef GXGDEP015OC1_H_
#define GXGDEP015OC1_H_

#include "GxEPD.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include "stddef.h"
#include <stdint.h>
#include "stdbool.h"

extern int rotation1;

// the physical number of pixels (for controller parameter)
#define GxGDEP015OC1_X_PIXELS 200
#define GxGDEP015OC1_Y_PIXELS 200

#define GxGDEP015OC1_WIDTH GxGDEP015OC1_X_PIXELS
#define GxGDEP015OC1_HEIGHT GxGDEP015OC1_Y_PIXELS

//#define GxGDEP015OC1_BUFFER_SIZE ((uint32_t(GxGDEP015OC1_WIDTH)) * (uint32_t(GxGDEP015OC1_HEIGHT)) / 8)
#define GxGDEP015OC1_BUFFER_SIZE 5000		////////////////////////////////////////////////////////////////////only for 200x200 e-paper display

// divisor for AVR, should be factor of GxGDEP015OC1_HEIGHT
#define GxGDEP015OC1_PAGES 5

#define GxGDEP015OC1_PAGE_HEIGHT (GxGDEP015OC1_HEIGHT / GxGDEP015OC1_PAGES)
#define GxGDEP015OC1_PAGE_SIZE (GxGDEP015OC1_BUFFER_SIZE / GxGDEP015OC1_PAGES)


// Display resolution
#define EPD_WIDTH       200
#define EPD_HEIGHT      200

// EPD1IN54 commands
#define DRIVER_OUTPUT_CONTROL                       0x01
#define BOOSTER_SOFT_START_CONTROL                  0x0C
#define GATE_SCAN_START_POSITION                    0x0F
#define DEEP_SLEEP_MODE                             0x10
#define DATA_ENTRY_MODE_SETTING                     0x11
#define SW_RESET                                    0x12
#define TEMPERATURE_SENSOR_CONTROL                  0x1A
#define MASTER_ACTIVATION                           0x20
#define DISPLAY_UPDATE_CONTROL_1                    0x21
#define DISPLAY_UPDATE_CONTROL_2                    0x22
#define WRITE_RAM                                   0x24
#define WRITE_VCOM_REGISTER                         0x2C
#define WRITE_LUT_REGISTER                          0x32
#define SET_DUMMY_LINE_PERIOD                       0x3A
#define SET_GATE_TIME                               0x3B
#define BORDER_WAVEFORM_CONTROL                     0x3C
#define SET_RAM_X_ADDRESS_START_END_POSITION        0x44
#define SET_RAM_Y_ADDRESS_START_END_POSITION        0x45
#define SET_RAM_X_ADDRESS_COUNTER                   0x4E
#define SET_RAM_Y_ADDRESS_COUNTER                   0x4F
#define TERMINATE_FRAME_READ_WRITE                  0xFF


    void GxGDEP015OC1_drawPixel(int16_t x, int16_t y, uint16_t color);
    void GxGDEP015OC1_init(uint32_t serial_diag_bitrate); // = 0 : disabled
    void GxGDEP015OC1_fillScreen(uint16_t color); // 0x0 black, >0x0 white, to buffer
    void update(void);
    // to buffer, may be cropped, drawPixel() used, update needed
    void  GxGDEP015OC1_drawBitmap1(const uint8_t *bitmap, uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color, int16_t mode);
    // to full screen, filled with white if size is less, no update needed
    void GxGDEP015OC1_drawBitmap2(const uint8_t *bitmap, uint32_t size, int16_t mode); // only bm_normal, bm_invert, bm_partial_update modes implemented
    void eraseDisplay(bool using_partial_update);
    // partial update of rectangle from buffer to screen, does not power off
    void updateWindow(uint16_t x, uint16_t y, uint16_t w, uint16_t h);
    // partial update of rectangle at (xs,ys) from buffer to screen at (xd,yd), does not power off
    void updateToWindow(uint16_t xs, uint16_t ys, uint16_t xd, uint16_t yd, uint16_t w, uint16_t h, bool using_rotation);
    // terminate cleanly updateWindow or updateToWindow before removing power or long delays
    void powerDown();
    // paged drawing, for limited RAM, drawCallback() is called GxGDEP015OC1_PAGES times
    // each call of drawCallback() should draw the same
    void drawPaged1(void (*drawCallback)(void));
    void drawPaged2(void (*drawCallback)(uint32_t), uint32_t);
    void drawPaged3(void (*drawCallback)(const void*), const void*);
    void drawPaged4(void (*drawCallback)(const void*, const void*), const void*, const void*);
    // paged drawing to screen rectangle at (x,y) using partial update
    void drawPagedToWindow1(void (*drawCallback)(void), uint16_t x, uint16_t y, uint16_t w, uint16_t h);
    void drawPagedToWindow2(void (*drawCallback)(uint32_t), uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint32_t);
    void drawPagedToWindow3(void (*drawCallback)(const void*), uint16_t x, uint16_t y, uint16_t w, uint16_t h, const void*);
    void drawPagedToWindow4(void (*drawCallback)(const void*, const void*), uint16_t x, uint16_t y, uint16_t w, uint16_t h, const void*, const void*);
    void drawCornerTest();

    void _writeToWindow(uint16_t xs, uint16_t ys, uint16_t xd, uint16_t yd, uint16_t w, uint16_t h);
    void _writeData(uint8_t data);
    void _writeCommand(uint8_t command);
    void _writeCommandData(const uint8_t* pCommandData, uint8_t datalen);
    void _SetRamPointer(uint8_t addrX, uint8_t addrY, uint8_t addrY1);
    void _SetRamArea(uint8_t Xstart, uint8_t Xend, uint8_t Ystart, uint8_t Ystart1, uint8_t Yend, uint8_t Yend1);
    void _PowerOn(void);
    void _PowerOff(void);
    void _waitWhileBusy(const char* comment, uint16_t busy_time);
    void _setRamDataEntryMode(uint8_t em);
    void _InitDisplay(uint8_t em);
    void _Init_Full(uint8_t em);
    void _Init_Part(uint8_t em);
    void _Update_Full(void);
    void _Update_Part(void);
    void _rotate(uint16_t x, uint16_t y, uint16_t w, uint16_t h);

    uint8_t _buffer[GxGDEP015OC1_BUFFER_SIZE];

    int16_t _current_page;
    bool _using_partial_mode;
    bool _diag_enabled;

    extern const uint8_t LUTDefault_part[];
    extern const uint8_t LUTDefault_full[];
    const uint8_t GDOControl[];
    const uint8_t softstart[];
    const uint8_t VCOMVol[];
    const uint8_t DummyLine[];
    const uint8_t Gatetime[];


#define GxEPD_Class GxGDEP015OC1
#define GxEPD_WIDTH GxGDEP015OC1_WIDTH
#define GxEPD_HEIGHT GxGDEP015OC1_HEIGHT
#define GxEPD_BitmapExamples <BitmapExamples.h>
#define GxEPD_BitmapExamplesQ "BitmapExamples.h"

#endif /* GXGDEP015OC1_H_ */
