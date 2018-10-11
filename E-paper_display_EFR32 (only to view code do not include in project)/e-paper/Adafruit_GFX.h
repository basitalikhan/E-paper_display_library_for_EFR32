/*
 * Adafruit_GFX.h
 *
 *  Created on: 29-Sep-2018
 *      Author: UTF-Labs-2
 */

#ifndef ADAFRUIT_GFX_H_
#define ADAFRUIT_GFX_H_

#include "gfxfont.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include "stddef.h"
#include <stdint.h>
#include "stdbool.h"

void setCursor(int16_t x, int16_t y);

void setTextSize(uint8_t s);

void setTextColor(uint16_t c);

uint8_t getRotation(void);

void setRotation(uint8_t r);

void setFont(const GFXfont *f);

void writePixel(int16_t x, int16_t y, uint16_t color);

void writeLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);

void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);

void writeFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);

void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);

void writeFillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);

void drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color,
      uint16_t bg, uint8_t size);

size_t write(uint8_t);



#endif /* ADAFRUIT_GFX_H_ */
