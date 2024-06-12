#include <jmp/mem.h>

#include <stdlib.h>
#include <assert.h>

Arena* Arena_new(sz size) {
  Arena* arena = malloc((sizeof(Arena)) + (sizeof(u8) * size));
  if (!arena) exit(-1);
  
  arena->mem_sz    = size;
  arena->alloc_ptr = 0;
  
  return arena;
}

void Arena_destroy(Arena* arena) {
  free(arena);
}

void* Arena_alloc(Arena* arena, sz size) {
  // This might not work.
  assert(arena->alloc_ptr + size <= arena->mem_sz);
  
  void* ptr = arena->mem + arena->alloc_ptr;
  arena->alloc_ptr += size;
  
  return ptr;
}

void Arena_free(Arena* arena) {
  arena->alloc_ptr = 0;
}
