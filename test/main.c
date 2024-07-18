#include <stdio.h>

#include <jmp.h>
#include <opt/rendr.h>

int main( void ) {
  Window *win = window_new("Test Window", 800, 600);
  Screen *scr = screen_new(800, 600);
  
  while (!should_quit()) {
    poll_updates();
    
    screen_clear(scr, color(0x2f2f2fff)); {
      // Draw on the screen.
    } window_draw(win, scr);
  }
  
  screen_destroy(scr);
  window_destroy(win);
  
  return 0;
}
