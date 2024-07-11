#ifndef __JMPC_OS_H
#define __JMPC_OS_H

#include <stdlib.h>
#include <stdio.h>

// Windows kinda sucks ngl.
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN64)
  #define Jmp_WIN
#elif defined(__linux__) || defined(__gnu_linux__)
  #define Jmp_LINUX
#else
  #error "Windows is the only currently supported os"
#endif

int flen(FILE *fptr);

#endif // __JMPC_OS_H
