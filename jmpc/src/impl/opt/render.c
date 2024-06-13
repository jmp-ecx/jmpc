#define __JMPC_RENDR_IMPL_PRIVATE_DECL
#include <opt/rendr.h>
#include <jmp/math.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <stdio.h>
#include <stdlib.h>
#ifdef Jmp_WIN
  #include <windows.h>
#endif

static const u8 chars[40][CHAR_H][CHAR_W] = {
  {
    { 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 1, 1, 0 },
    { 0, 0, 1, 0, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 1, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 1, 1, 1, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 0, 0, 1, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 1, 1, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 0, 0, 1, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 0, 1, 0, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 1, 1, 1 },
    { 0, 0, 0, 1, 0 },
    { 0, 0, 0, 1, 0 },
    { 0, 0, 0, 1, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 1, 1, 1, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 0, 1, 0 },
    { 0, 0, 0, 1, 0 },
    { 0, 1, 1, 1, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 1, 0, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 0, 1, 0, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 1, 1, 1, 0 },
    { 0, 0, 0, 1, 0 },
    { 0, 0, 0, 1, 0 },
    { 0, 0, 0, 1, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 0, 1, 0, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 0, 1, 1, 0 },
    { 0, 0, 0, 1, 0 },
    { 0, 0, 0, 1, 0 },
    { 0, 0, 0, 1, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 1, 1, 1, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 1, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 1, 1, 0, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 1, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 1, 0, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 0, 1, 0, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 1, 1, 0, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 1, 0, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 1, 1, 1, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 1, 0, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 1, 1, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 1, 1, 1, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 1, 0, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 0, 0, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 1, 1, 1, 0 },
    { 1, 0, 0, 0, 0 },
    { 1, 0, 0, 0, 0 },
    { 1, 0, 1, 0, 0 },
    { 1, 0, 0, 1, 0 },
    { 1, 0, 0, 1, 0 },
    { 0, 1, 1, 1, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 1, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 1, 1, 1, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 1, 1, 1, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 1, 1, 1, 0 },
    { 0, 0, 0, 1, 0 },
    { 0, 0, 0, 1, 0 },
    { 0, 0, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 0, 1, 0, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 1, 0, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 1, 1, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 1, 0, 0, 0, 1 },
    { 1, 1, 0, 1, 1 },
    { 1, 0, 1, 0, 1 },
    { 1, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 1 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 1, 0, 0, 1, 0 },
    { 1, 1, 0, 1, 0 },
    { 1, 0, 1, 1, 0 },
    { 1, 0, 0, 1, 0 },
    { 1, 0, 0, 1, 0 },
    { 1, 0, 0, 1, 0 },
    { 1, 0, 0, 1, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 1, 1, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 1, 1, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 1, 1, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 1, 1, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 0, 0, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 1, 1, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 1, 1, 1 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 1, 1, 0, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 1, 0, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 1, 1, 1, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 0, 0, 0 },
    { 0, 1, 1, 1, 0 },
    { 0, 0, 0, 1, 0 },
    { 0, 0, 0, 1, 0 },
    { 0, 1, 1, 1, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 1, 1, 1, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 1, 1, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 1, 1, 0 },
    { 0, 0, 1, 0, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 1, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 1 },
    { 1, 0, 1, 0, 1 },
    { 1, 0, 1, 0, 1 },
    { 1, 0, 1, 0, 1 },
    { 0, 1, 0, 1, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 0 },
    { 0, 0, 0, 1, 0 },
    { 0, 0, 0, 1, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 1, 0, 0, 0 },
    { 1, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
  },
  {
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 0, 0, 0, 0 },
  },
};
static const u8* glyphs = chars; // This is for a hacky workaround to an issue I don't know how to solve.

static int event_state[3] = { 0 };

struct Window {
  int width, height;
#ifdef Jmp_WIN
  HWND hwnd;
  WNDCLASS wc;
#endif
};

struct Screen {
  sz width, height;
  u32 buf[1];
};

struct PxBuffer {
  sz width, height;
  u32 buf[1];
};

Screen* screen_new(sz width, sz height) {
  Screen* scr = malloc(sizeof(Screen) + (sizeof(u32) * width * height) - 1);
  if (!scr) exit(-1);

  scr->width = width;
  scr->height = height;

  return scr;
}

void screen_destroy(Screen* scr) {
  free(scr);
}

void screen_clear(Screen* scr, u32 col) {
  for (sz i = 0; i < scr->width * scr->height; ++i) {
    scr->buf[i] = col;
  }
}

void screen_px(Screen* scr, sz x, sz y, u32 col) {
  if (x >= scr->width) return;
  if (y >= scr->height) return;

  sz p_x = x;
  sz p_y = scr->height - y - 1;

  scr->buf[idx2d(p_x, p_y, scr->width)] = col;
}

void screen_rect(Screen* scr, sz x, sz y, sz w, sz h, u32 col) {
  for (sz sy = y; sy < y + h; ++sy) {
    for (sz sx = x; sx < x + w; ++sx) {
      screen_px(scr, sx, sy, col);
    }
  }
}

void screen_draw_pixel_buffer(Screen* scr, sz x, sz y, PxBuffer* buf) {
  for (sz sy = 0; sy < buf->height; ++sy) {
    for (sz sx = 0; sx < buf->width; ++sx) {
      screen_px(scr, sx+x, sy+y, buf->buf[idx2d(sx, sy, buf->width)]);
    }
  }
}

void screen_draw_char(Screen* scr, char c, sz x, sz y, sz scale, u32 col) {
  sz si = 0;
  sz sj = 0;

  u8 nc = 0;
  c = toupper(c);

  switch (c) {
  case '0': nc = 0; break;
  case '1': nc = 1; break;
  case '2': nc = 2; break;
  case '3': nc = 3; break;
  case '4': nc = 4; break;
  case '5': nc = 5; break;
  case '6': nc = 6; break;
  case '7': nc = 7; break;
  case '8': nc = 8; break;
  case '9': nc = 9; break;
  case '-': nc = 10; break;
  case '.': nc = 11; break;
  case 'A': nc = 12; break;
  case 'B': nc = 13; break;
  case 'C': nc = 14; break;
  case 'D': nc = 15; break;
  case 'E': nc = 16; break;
  case 'F': nc = 17; break;
  case 'G': nc = 18; break;
  case 'H': nc = 19; break;
  case 'I': nc = 20; break;
  case 'J': nc = 21; break;
  case 'K': nc = 22; break;
  case 'L': nc = 23; break;
  case 'M': nc = 24; break;
  case 'N': nc = 25; break;
  case 'O': nc = 26; break;
  case 'P': nc = 27; break;
  case 'Q': nc = 28; break;
  case 'R': nc = 29; break;
  case 'S': nc = 30; break;
  case 'T': nc = 31; break;
  case 'U': nc = 32; break;
  case 'V': nc = 33; break;
  case 'W': nc = 34; break;
  case 'X': nc = 35; break;
  case 'Y': nc = 36; break;
  case 'Z': nc = 37; break;
  case ' ': nc = 38; break;
  case ':': nc = 39; break;
  default: nc = 10;
  }

  for (sz j = 0; j < CHAR_H; ++j) {
    for (sz i = 0; i < CHAR_W; ++i) {
      if (glyphs[(nc * CHAR_W * CHAR_H) + i + (j * CHAR_W)]) {
      screen_rect(scr, x + si, y + sj, scale, scale, col);
      }
      si += scale;
    }
    si = 0;
    sj += scale;
  }
}

PxBuffer *pxbuf_new(sz width, sz height) {
  PxBuffer* buf = malloc(sizeof(PxBuffer) + (sizeof(u32) * width * height) - 1);
  if (!buf) exit(-1);

  buf->width = width;
  buf->height = height;

  return buf;
}

PxBuffer *pxbuf_from_img(const char *fpath) {
  int w, h, c;
  u8 *data = stbi_load(fpath, &w, &h, &c, 4);
  if (data == NULL) exit(-3);
  
  PxBuffer *buf = pxbuf_new(w, h);
  
  sz i = 0;
  u32 tmp = 0;
  for (sz j = 0; j < w*h*4; ++j) {
    tmp <<= 8;
    tmp |= data[j++];
    if (j % 4 == 0) {
      buf->buf[i++] = tmp;
    }
  }
  
  return buf;
}

void pxbuf_destroy(PxBuffer* buf) {
  free(buf);
}

void pxbuf_clear(PxBuffer* buf, u32 col) {
  for (sz i = 0; i < buf->width * buf->height; ++i) {
    buf->buf[i] = col;
  }
}

void pxbuf_px(PxBuffer* buf, sz x, sz y, u32 col) {
  if (x >= buf->width) return;
  if (y >= buf->height) return;

  sz p_x = x;
  sz p_y = buf->height - y - 1;

  buf->buf[idx2d(p_x, p_y, buf->width)] = col;
}

#ifdef Jmp_WIN
static LRESULT window_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
  if (msg == WM_CLOSE) {
    DestroyWindow(hwnd);
  }
  else if (msg == WM_DESTROY) {
    PostQuitMessage(0);
  }
  return DefWindowProc(hwnd, msg, wparam, lparam);
};

Window *window_new(char* name, int width, int height) {
  WNDCLASS wc = { CS_CLASSDC, window_proc };
  wc.lpszClassName = name;
  wc.hCursor = LoadCursor(NULL, IDC_ARROW);
  RegisterClass(&wc);

  HWND hwnd = CreateWindow(wc.lpszClassName, name,
    WS_OVERLAPPED | WS_SYSMENU | WS_VISIBLE,
    CW_USEDEFAULT, CW_USEDEFAULT, width, height, NULL, NULL, NULL, NULL);

  Window* win = malloc(sizeof(Window));
  
  win->width  = width;
  win->height = height;
  win->hwnd   = hwnd;
  win->wc     = wc;
  
  return win;
}

void window_destroy(Window* win) {
  free(win);
}

void window_draw(Window* win, Screen* scr) {
  BITMAPINFOHEADER bmi = { sizeof(bmi), scr->width, scr->height, 1, 32 };
  HDC dc = GetDC(win->hwnd);
  SetDIBitsToDevice(dc, 0, 0, scr->width, scr->height, 0, 0, 0u, scr->height, scr->buf,
    (BITMAPINFO*)&bmi, DIB_RGB_COLORS);
  ReleaseDC(win->hwnd, dc);
}

void poll_updates( void ) {
  MSG msg;
  while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
    switch (msg.message) {
      case WM_QUIT:        event_state[JMP_QUIT]        = 1; break;
      case WM_LBUTTONDOWN: event_state[JMP_LFT_MBUTTON] = 1; break;
      case WM_LBUTTONUP:   event_state[JMP_LFT_MBUTTON] = 0; break;
      case WM_RBUTTONDOWN: event_state[JMP_RT_MBUTTON]  = 1; break;
      case WM_RBUTTONUP:   event_state[JMP_RT_MBUTTON]  = 0; break;
    }
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
}

vec2 mouse_pos(Window *win) {
  POINT p;
  
  if (!GetCursorPos(&p)) return (vec2) { 0, 0 };
  ScreenToClient(win->hwnd, &p);
  
  int x = iclamp(p.x, 0, win->width);
  int y = iclamp(p.y, 0, win->height);
  
  return (vec2) { x, y };
}
#endif // Window operations, for the Windows OS

int should_quit( void ) { return event_state[JMP_QUIT]; }
int mousebutton_left( void ) {return event_state[JMP_LFT_MBUTTON]; }
int mousebutton_right( void ) {return event_state[JMP_RT_MBUTTON]; }
