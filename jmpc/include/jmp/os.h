#ifndef __JMPC_OS_H
#define __JMPC_OS_H

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
  #define Jmp_WIN
#elif defined(__linux__) || defined(__gnu_linux__)
  #define Jmp_LINUX
#else
  #error "Windows is the only currently supported os"
#endif  

#endif // __JMPC_OS_H
