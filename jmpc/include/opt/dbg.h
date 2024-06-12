#ifndef __RT_GFX_UTIL_H
#define __RT_GFX_UTIL_H

#include <jmp.h>
#include <opt/rendr.h>

void lnreset(void);
void idbg(Screen* scr, int num, sz scale, u32 col);
void xdbg(Screen* scr, u32 num, sz scale, u32 col);
void fdbg(Screen* scr, f32 num, sz scale, u32 col);
void sdbg(Screen* scr, char* txt, sz scale, u32 col);

void idbg_lf(Screen* scr, int num, sz scale, u32 col);
void xdbg_lf(Screen* scr, u32 num, sz scale, u32 col);
void fdbg_lf(Screen* scr, f32 num, sz scale, u32 col);
void sdbg_lf(Screen* scr, char* txt, sz scale, u32 col);
 
#endif // __RT_GFX_UTIL_H
