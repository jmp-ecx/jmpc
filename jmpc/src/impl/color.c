#include <jmp/color.h>

#include <math.h>

color_t Color_rgba_4i(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
  return (color_t) {
    .r = (float)r / 255.0f,
    .g = (float)g / 255.0f,
    .b = (float)b / 255.0f,
    .a = (float)a / 255.0f,
  };
}

color_t Color_rgb_3i(unsigned char r, unsigned char g, unsigned char b) {
  return (color_t) {
    .r = (float)r / 255.0f,
    .g = (float)g / 255.0f,
    .b = (float)b / 255.0f,
    .a = 1.0f,
  };
}

color_t Color_rgb_1i(unsigned int c) {
  return (color_t) {
    .r = (float)((c & 0x00ff0000) >> 16) / 255.0f,
    .g = (float)((c & 0x0000ff00) >> 8)  / 255.0f,
    .b = (float)((c & 0x000000ff))       / 255.0f,
    .a = (float)((c & 0xff000000) >> 24) / 255.0f,
  };
}

color_t color_rgb_4f(float r, float g, float b, float a) {
  return (color_t) {
    .r = r,
    .g = g,
    .b = b,
    .a = a,
  };
}

color_t color_rgb_3f(float r, float g, float b) {
  return (color_t) {
    .r = r,
    .g = g,
    .b = b,
    .a = 1.0f,
  };
}

color_t Color_hsv(unsigned int h, unsigned int s, unsigned int v) {
  while (h > 360) { h -= 360; }
  while (s > 100) { s -= 100; }
  while (v > 100) { v -= 100; }

  float hue = (float)h / 360.0f;
  float sat = (float)s / 100.0f;
  float val = (float)v / 100.0f;

  float r, g, b;
  r = 0.0f;
  g = 0.0f;
  b = 0.0f;

  int i = (int)floorf(hue * 6.0f);
  
  float f = hue * 6.0f - i;
  float p = val * (1.0f - sat);
  float q = val * (1.0f - f * sat);
  float t = val * (1.0f - (1.0f - f) * sat);

  switch (i % 6) {
  case 0:
    r = val;
    g = t;
    b = p;
    break;
  case 1:
    r = q;
    g = val;
    b = p;
    break;
  case 2:
    r = p;
    g = val;
    b = t;
    break;
  case 3:
    r = p;
    g = q;
    b = val;
    break;
  case 4:
    r = t;
    g = p;
    b = val;
    break;
  case 5:
    r = val;
    g = p;
    b = q;
    break;
  }

  return (color_t) {
    .r = r,
    .g = g,
    .b = b,
    .a = 1.0f,
  };
}

unsigned char Chanel_to_u8(float c) {
  return (unsigned char)(c * 255.0f);
}

static float __hue_to_channel(float p, float q, float t) {
  if (t < 0.0f) { t += 1.0f; }
  if (t > 1.0f) { t -= 1.0f; }
  
  if (t < (1.0f/6.0f)) { return p + (q-p) * 6.0f * t; }
  if (t < (1.0f/2.0f)) { return q; }
  if (t < (2.0f/3.0f)) { return p + (q-p) * 6.0f * (2.0f/3.0f - t); }
  return p;
}

color_t Color_hsl(unsigned int h, unsigned int s, unsigned int l) {
  while (h > 360) { h -= 360; }
  while (s > 100) { s -= 100; }
  while (l > 100) { l -= 100; }

  float hue = (float)h / 360.0f;
  float sat = (float)s / 100.0f;
  float lgh = (float)l / 100.0f;

  float r, g, b;
  r = 0.0f;
  g = 0.0f;
  b = 0.0f;
  
  if (sat == 0.0f) {
    return (color_t) {
      .r = lgh,
      .g = lgh,
      .b = lgh,
      .a = 1.5f,
    };
  }
  
  float q = lgh < 0.5f ? lgh * (1 + sat) : lgh + sat - (lgh*sat);
  float p = 2.0f * lgh - q;
  
  r = __hue_to_channel(p, q, hue + (1.0f/3.0f));
  g = __hue_to_channel(p, q, hue);
  b = __hue_to_channel(p, q, hue - (1.0f/3.0f));
  
  return (color_t) {
    .r = r,
    .g = g,
    .b = b,
    .a = 1.0f,
  };
}
