#include <opt/dbg.h>
#include <jmp.h>

#include <stdio.h>

static sz scr_x = 0;
static sz scr_y = 0; 

void lnreset(void) {
  scr_x = 0;
  scr_y = 0;
}

// TODO - maybe possibly make these not show up in release mode.

void idbg(Screen* scr, int num, sz scale, u32 col) {
  char str[11];
  
  sprintf(str, "%d", num);

  int i = 0;
  while (str[i]) {
    screen_draw_char(scr, str[i], scr_x, scr_y, scale, col);
    scr_x += CHAR_W * scale;
    i++;
  }
}

void xdbg(Screen* scr, u32 num, sz scale, u32 col) {
  char str[9];
  
  sprintf(str, "%X", num);

  int i = 0;
  while (str[i]) {
    screen_draw_char(scr, str[i], scr_x, scr_y, scale, col);
    scr_x += CHAR_W * scale;
    i++;
  }
}

void fdbg(Screen* scr, f32 num, sz scale, u32 col) {
  char str[50];

  sprintf(str, "%f", num);

  int i = 0;
  while (str[i]) {
    screen_draw_char(scr, str[i], scr_x, scr_y, scale, col);
    scr_x += CHAR_W * scale;
    i++;
  }
}

void sdbg(Screen* scr, char* txt, sz scale, u32 col) {
  int i = 0;
  while (txt[i]) {
    screen_draw_char(scr, txt[i], scr_x, scr_y, scale, col);
    scr_x += CHAR_W * scale;
    i++;
  }
}

void idbg_lf(Screen* scr, int num, sz scale, u32 col) {
  idbg(scr, num, scale, col);
  scr_x = 0;
  scr_y += CHAR_H * scale;
}

void xdbg_lf(Screen* scr, u32 num, sz scale, u32 col) {
  xdbg(scr, num, scale, col);
  scr_x = 0;
  scr_y += CHAR_H * scale;
}

void fdbg_lf(Screen* scr, f32 num, sz scale, u32 col) {
  fdbg(scr, num, scale, col);
  scr_x = 0;
  scr_y += CHAR_H * scale;
}

void sdbg_lf(Screen* scr, char* txt, sz scale, u32 col) {
  sdbg(scr, txt, scale, col);
  scr_x = 0;
  scr_y += CHAR_H * scale;
}
