#ifndef __JMPC_MEM_H
#define __JMPC_MEM_H

#include <jmp/types.h>

#include <stdlib.h>

// Common memory sizes / allignments
#define Jmp_1KiB  1024
#define Jmp_4KiB  4096
#define Jmp_16KiB 16384
#define Jmp_64KiB 65536
#define Jmp_1MiB  1048576
#define Jmp_16MiB 16777216
#define Jmp_64MiB 67108864
#define Jmp_1GiB  1073741824

// Macros to calculate an arbitrary byte size.
#define Jmp_TiB(s) (s * 1024 * 1024 * 1024 * 1024)
#define Jmp_GiB(s) (s * 1024 * 1024 * 1024)
#define Jmp_MiB(s) (s * 1024 * 1024)
#define Jmp_KiB(s) (s * 1024)

// Macros to memory management functions, to allow for easy
// drop-in swapping, for things like debug libs.
#define malloc(size)        malloc(size)
#define calloc(count, size) calloc(count, size)
#define realloc(ptr, size)  realloc(ptr, size)
#define free(ptr)           free(ptr)

// A custom linear arena allocator.
typedef struct {
  sz mem_sz;
  sz alloc_ptr;
  u8 mem[];
} Arena;

Arena* Arena_new(sz size);
void   Arena_destroy(Arena* arena);
void*  Arena_alloc(Arena* arena, sz size);
void   Arena_free(Arena* arena);

#endif // __JMPC_MEM_H
