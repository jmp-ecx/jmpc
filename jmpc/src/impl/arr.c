#include <jmp/arr.h>
#include <jmp.h>

dyn_arr dyn_arr_new(sz capacity, sz data_sz) {
  void* ptr = malloc(data_sz * capacity);
  if (!ptr) exit(-1);
  
  return (dyn_arr) {
    .cap = capacity,
    .size = 0,
    .data_sz = data_sz,
    .ptr = ptr,
  };
}

void dyn_arr_resize(dyn_arr* arr, sz new_size) {
  arr->cap = new_size;
  arr->ptr = realloc(arr->ptr, new_size * arr->data_sz);
  if (!arr->ptr) exit(-1);
}

void dyn_arr_append(dyn_arr* arr, void* data) {
  arr->ptr[arr->size++] = data;
  
  if (arr->size == arr->cap) {
    dyn_arr_resize(arr, arr->size * 2); // TODO - find a better number.
  }
}
