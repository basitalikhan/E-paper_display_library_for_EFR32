/*
 * GxFont_GFX.c
 *
 *  Created on: 29-Sep-2018
 *      Author: UTF-Labs-2
 */


// Library: https://github.com/ZinggJM/GxEPD

#include "GxFont_GFX.h"

//#define DIAG(x) x

// #ifndef DIAG
// #define DIAG(x)
// #endif

enum eFont_GFX
{
  U8g2_for_Adafruit_GFX_font_gfx, Adafruit_GFX_font_gfx, Adafruit_ftGFX_font_gfx, GxFont_GFX_TFT_eSPI_font_gfx
};

//GxFont_GFX::GxFont_GFX(int16_t w, int16_t h) : Adafruit_GFX(w, h)
// #if defined(U8g2_for_Adafruit_GFX_h)
  // , _U8G2_FONTS_GFX(*this)
// #endif
// #if defined(_ADAFRUIT_TF_GFX_H_)
  // , _GxF_Adafruit_ftGFX(*this, w, h)
// #endif
// #if defined(_GxFont_GFX_TFT_eSPI_H_)
  // , _GxF_GxFont_GFX_TFT_eSPI(*this, w, h)
// #endif
// {
  _font_gfx = Adafruit_GFX_font_gfx;
// }

//void setFont(const GFXfont *f)
//{
//  _font_gfx = Adafruit_GFX_font_gfx;
//  Adafruit_GFX_setFont(f);
//}
