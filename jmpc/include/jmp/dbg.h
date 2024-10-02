#ifndef __JMPC_DBG_H
#define __JMPC_DBG_H

#include <jmp/types.h>

// A set of tools to aid debugging code.
// This is all WIP, so nothing is final.

// TODO - debugging / tracing allocators

void *jmp_dbg_malloc(sz size, const char *FILE, const int LINE);
void  jmp_dbg_free(void* ptr, const char *FILE, const int LINE);

#ifdef Jmp_DEBUG_MEMORY_TRACER
  #ifdef malloc
    #undef malloc
  #endif
  #ifdef free
    #undef free
  #endif
  
  #define malloc(size) jmp_dbg_malloc(size, __FILE__, __LINE__)
  #define free(ptr) jmp_dbg_free(ptr, __FILE__, __LINE__)
#endif // Jmp_DEBUG_MEMORY_TRACER

#endif // __JMPC_DBG_H
