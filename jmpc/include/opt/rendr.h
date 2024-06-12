#ifndef __JMPC_OPT_RENDERER_H
#define __JMPC_OPT_RENDERER_H

#include <jmp/os.h>
#include <jmp/types.h>

// TODO - Linux Support
#ifdef Jmp_WIN
#else
  #error "Windows is the only supported OS for the render module."
#endif

#define idx2d(x, y, s) (y*s) + x
#define color(col) ((u32)(col&0xff)<<24) | ((col&0xffffff00)>>8)

#define CHAR_W 5
#define CHAR_H 8

#define JMP_QUIT 0
#define JMP_LFT_MBUTTON 1
#define JMP_RT_MBUTTON 2

#ifndef __JMPC_RENDR_IMPL_PRIVATE_DECL
  typedef void Window;
  typedef void Screen;
  typedef void PxBuffer;
#else
  typedef struct Window   Window;
  typedef struct Screen   Screen;
  typedef struct PxBuffer PxBuffer;
#endif

Screen* screen_new(sz width, sz height);
void    screen_destroy(Screen* scr);
void    screen_clear(Screen *scr, u32 col);
void    screen_px(Screen* scr, sz x, sz y, u32 col);
void    screen_rect(Screen* scr, sz x, sz y, sz w, sz h, u32 col);
void    screen_draw_pixel_buffer(Screen* scr, sz x, sz y, PxBuffer* buf);
void    screen_draw_char(Screen* scr, char c, sz x, sz y, sz scale, u32 col);

PxBuffer *pxbuf_new(sz width, sz height);
PxBuffer *pxbuf_from_img(const char *fpath);
void      pxbuf_destroy(PxBuffer* buf);
void      pxbuf_clear(PxBuffer* buf, u32 col);
void      pxbuf_px(PxBuffer* buf, sz x, sz y, u32 col);

Window *window_new(char* name, int width, int height);
void    window_destroy(Window* win);
void    window_draw(Window* win, Screen* scr);

void poll_updates( void );
int  should_quit( void );
int  mousebutton_left( void );
int  mousebutton_right( void );

// TODO
vec2 mouse_pos(Window *win);

#endif // __JMPC_OPT_RENDERER_H
