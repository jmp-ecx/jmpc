#include <jmp/mem.h>

#include <stdlib.h>
#include <assert.h>

arena_t* arena_new(sz size) {
  arena_t* arena = malloc((sizeof(arena_t)) + (sizeof(u8) * size));
  if (!arena) exit(-1);
  
  arena->mem_sz    = size;
  arena->alloc_ptr = 0;
  
  return arena;
}

void* arena_alloc(arena_t* arena, sz size) {
  // This might not work.
  assert(arena->alloc_ptr + size <= arena->mem_sz);
  
  void* ptr = arena->mem + arena->alloc_ptr;
  arena->alloc_ptr += size;
  
  return ptr;
}

void arena_free(arena_t* arena) {
  arena->alloc_ptr = 0;
}

rbuf_t* rbuf_new(sz buffer_size, sz data_size) {
  rbuf_t* buffer = malloc((sizeof(rbuf_t)) + (sizeof(u8) * buffer_size));
  if (!buffer) exit(-1);
  
  buffer->buf_sz    = buffer_size;
  buffer->data_sz   = data_size;
  buffer->read_idx  = 0;
  buffer->write_idx = 0;
  
  return buffer;
}

void rbuf_write(rbuf_t* buf, void* data) {
  // write_idx = (write_idx + data_sz) % buffer_size
  
  buf->mem[buf->write_idx] = data;
  
  buf->write_idx = (buf->write_idx + buf->data_sz) % buf->buf_sz;
}

void* rbuf_get(rbuf_t* buf) {
  // TODO - check if read ptr == write pointer, and if so, have a stroke and die.
  
  void* res = buf->mem[buf->read_idx];
  
  buf->read_idx = (buf->read_idx + buf->data_sz) % buf->buf_sz;
  
  return res;
}

void destroy(void* region) {
  free(region);
}
