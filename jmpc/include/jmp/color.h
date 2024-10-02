#ifndef __JMPC_COLOR_H
#define __JMPC_COLOR_H

#include <jmp.h>

typedef struct Rgb {
  u8 r, g, b, a;
} rgb_c;

typedef struct Hsv {
  f32 h, s, v;
} hsv_c;

rgb_c hsv_to_rgb(hsv_c hsv);

rgb_c rgb_interpolate(rgb_c a, rgb_c b, f32 fraction);
u32 rgb_to_hex(rgb_c rgb);

#endif // __JMP_COLOR_H
