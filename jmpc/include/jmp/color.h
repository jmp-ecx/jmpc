#ifndef __JMPC_COLOR_H
#define __JMPC_COLOR_H

#include <jmp.h>

typedef struct Color {
  float r, g, b, a;
} color_t;

color_t Color_rgba_4i(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
color_t Color_rgb_3i(unsigned char r, unsigned char g, unsigned char b);
color_t Color_rgb_1i(unsigned int c);

color_t color_rgb_4f(float r, float g, float b, float a);
color_t color_rgb_3f(float r, float g, float b);

color_t Color_hsv(unsigned int h, unsigned int s, unsigned int v);
color_t Color_hsl(unsigned int h, unsigned int s, unsigned int l);

unsigned char Chanel_to_u8(float c);

#endif // __JMPC_COLOR_H
