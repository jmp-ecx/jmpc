#ifndef __JMPC_COLOR_H
#define __JMPC_COLOR_H

#include <jmp.h>

typedef struct Color {
  f32 r, g, b, a;
} color_t;

color_t Color_rgba_4i(u8 r, u8 g, u8 b, u8 a);
color_t Color_rgb_3i(u8 r, u8 g, u8 b);
color_t Color_rgb_1i(u32 c);

color_t color_rgb_4f(f32 r, f32 g, f32 b, f32 a);
color_t color_rgb_3f(f32 r, f32 g, f32 b);

u8 Chanel_to_u8(f32 c);

color_t Color_hsv(u32 h, u32 s, u32 v);
color_t Color_hsl(u32 h, u32 s, u32 l);

#endif // __JMPC_COLOR_H
