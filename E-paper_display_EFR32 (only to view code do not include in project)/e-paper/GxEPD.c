/*
 * GxEPD.c
 *
 *  Created on: 28-Sep-2018
 *      Author: UTF-Labs-2
 */


// class GxEPD : Base Class for Display Classes for e-Paper Displays from Dalian Good Display Co., Ltd.: www.good-display.com
//

//
// Library: https://github.com/ZinggJM/GxEPD

#include "GxEPD.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include "stddef.h"
#include <stdint.h>
#include "stdbool.h"

//uint16_t gx_uint16_min(uint16_t a, uint16_t b) {return (a < b ? a : b);};
//uint16_t gx_uint16_max(uint16_t a, uint16_t b) {return (a > b ? a : b);};

void GxEPD_drawBitmapBM(const uint8_t *bitmap, uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color, int16_t mode)
{
  uint16_t inverse_color = (color != GxEPD_WHITE) ? GxEPD_WHITE : GxEPD_BLACK;
  uint16_t fg_color = (mode & bm_invert) ? inverse_color : color;
  uint16_t bg_color = (mode & bm_invert) ? color : inverse_color;
  // taken from Adafruit_GFX.cpp, modified
  int16_t byteWidth = (w + 7) / 8; // Bitmap scanline pad = whole byte
  uint8_t byte = 0;
  if (mode & bm_transparent)
  {
    for (int16_t j = 0; j < h; j++)
    {
      for (int16_t i = 0; i < w; i++ )
      {
        if (i & 7) byte <<= 1;
        else
        {
          byte = bitmap[j * byteWidth + i / 8];
        }
        // transparent mode
        bool temporary1 = (mode & bm_invert);
        bool temporary2 = (byte & 0x80);

        if (temporary1 != temporary2)
        //if (!(byte & 0x80))
        {
          uint16_t xd = x + i;
          uint16_t yd = y + j;
          if (mode & bm_flip_x) xd = x + w - i;
          if (mode & bm_flip_y) yd = y + h - j;
          GxGDEP015OC1_drawPixel(xd, yd, color);
        }
      }
    }
  }
  else
  {
    for (int16_t j = 0; j < h; j++)
    {
      for (int16_t i = 0; i < w; i++ )
      {
        if (i & 7) byte <<= 1;
        else
        {
          byte = bitmap[j * byteWidth + i / 8];
        }
        // keep using overwrite mode
        uint16_t pixelcolor = (byte & 0x80) ? fg_color  : bg_color;
        uint16_t xd = x + i;
        uint16_t yd = y + j;
        if (mode & bm_flip_x) xd = x + w - i;
        if (mode & bm_flip_y) yd = y + h - j;
        GxGDEP015OC1_drawPixel(xd, yd, pixelcolor);
      }
    }
  }
}
