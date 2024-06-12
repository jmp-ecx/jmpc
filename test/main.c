#include <stdio.h>

#include <jmp.h>
#include <opt/rendr.h>
#include <opt/dbg.h>

#include <windows.h>

const int WINDOW_WIDTH  = 800;
const int WINDOW_HEIGHT = 600;

static u32 wonky_colors(int x, int y) {
  int r = (int)((y / (float)WINDOW_HEIGHT)     * 255);
  int g = (int)((x / (float)WINDOW_WIDTH  / 2) * 255) + 255
        - (int)((y / (float)WINDOW_HEIGHT / 2) * 255);
  int b = (int)((x / (float)WINDOW_WIDTH)      * 255);
  return (255<24) | (r<<16) | (g<<8) | b;
}

int main( void ) {
  Window *win = window_new("Test Window", WINDOW_WIDTH, WINDOW_HEIGHT);
  Screen *scr = screen_new(WINDOW_WIDTH, WINDOW_HEIGHT);
  
  while (!should_quit()) {
    for (int i = 0; i < WINDOW_HEIGHT; ++i) {
      for (int j = 0; j < WINDOW_WIDTH; ++j) {
        if (mousebutton_left()) {
          screen_px(scr, j, i, wonky_colors(i, j));
        } else {
          screen_px(scr, j, i, wonky_colors(j, i));
        }
      }
    }
    
    vec2 p = mouse_pos(win);
    lnreset();
    idbg_lf(scr, p.x, 3, color(0xff0000ff));
    idbg_lf(scr, p.y, 3, color(0xff0000ff));
    
    window_draw(win, scr);
    poll_updates();
  }
  
  screen_destroy(scr);
  window_destroy(win);
  
  return 0;
}
