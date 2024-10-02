#include <jmp/color.h>

#include <math.h>

rgb_c hsv_to_rgb(hsv_c hsv) {
  if (hsv.h > 360.0f) exit(-1);
  if (hsv.s > 1.0f)   exit(-1);
  if (hsv.v > 1.0f)   exit(-1);
  
  float h = hsv.h / 360.0f;
  float s = hsv.s;
  float v = hsv.v;
  
  int i = (int)floorf(h * 6.0f);
  float f = h * 6.0f - i;
  float p = v * (1.0f - s);
  float q = v * (1.0f - f*s);
  float t = v * (1.0f - (1.0f - f)*s);

  float rr, rg, rb;
  switch (i % 6) {
  case 0: 
    rr = v;
    rg = t;
    rb = p;
    break;
  case 1: 
    rr = q;
    rg = v;
    rb = p;
    break;
  case 2: 
    rr = p;
    rg = v;
    rb = t;
    break;
  case 3: 
    rr = p;
    rg = q;
    rb = v;
    break;
  case 4: 
    rr = t;
    rg = p;
    rb = v;
    break;
  case 5: 
    rr = v;
    rg = p;
    rb = q;
    break;
  default:
    rr = 0;
    rg = 0;
    rb = 0;
  }

  return (rgb_c) {
    .r = (u8)(rr * 255),
    .g = (u8)(rg * 255),
    .b = (u8)(rb * 255),
    .a = 255,
  };
}

static f32 rgb_to_linear(u8 c) {
  float s = c / 255.0f;
  return s <= 0.04045 ? s / 12.92 : pow((s + 0.055) / 1.055, 2.4);
}

static u8 linear_to_rgb(f32 linear) {
  float s = linear <= 0.0031308 ? linear * 12.92 : 1.055 * pow(linear, 1.0/2.4) - 0.055;
    return (u8) (s * 255);
}

static u8 interpolate_chanel(u8 a, u8 b, f32 fraction) {
  float c1 = rgb_to_linear(a);
  float c2 = rgb_to_linear(b);
  return linear_to_rgb((c2 - c1) * fraction + c1);
}

rgb_c rgb_interpolate(rgb_c a, rgb_c b, f32 fraction) {
  return (rgb_c) {
    .r = interpolate_chanel(a.r, b.r, fraction),
    .g = interpolate_chanel(a.g, b.g, fraction),
    .b = interpolate_chanel(a.b, b.b, fraction),
  };
}

u32 rgb_to_hex(rgb_c rgb) {
  return (rgb.r << 24) | (rgb.g << 16) | (rgb.b << 8) | rgb.a; 
}
