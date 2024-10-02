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
#define Jmp_4GiB  4294967296

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

typedef struct Arena {
  sz mem_sz;
  sz alloc_ptr;
  sz read_ptr;
  u8 mem[];
} arena_t;

typedef struct RingBuffer {
  sz buf_sz, data_sz;
  sz read_idx, write_idx;
  u8 mem[];
} rbuf_t;

arena_t* arena_new(sz size);
void*    arena_alloc(arena_t* arena, sz size);
void     arena_free(arena_t* arena);

rbuf_t* rbuf_new(sz buffer_size, sz data_size);
void    rbuf_write(rbuf_t* buf, void* data);
void*   rbuf_get(rbuf_t* buf);
#define rbuf_read(buf, type) (type)rbuf_get(buf)

void destroy(void* region);

#endif // __JMPC_MEM_H
