#ifndef __JMPC_DYN_ARRAY_H
#define __JMPC_DYN_ARRAY_H

#include <jmp.h>

typedef struct DynamicArray {
  sz  cap;
  sz  size;
  sz  data_sz;
  u8* ptr;
} dyn_arr;

dyn_arr dyn_arr_new(sz capacity, sz data_sz);
void dyn_arr_destroy(dyn_arr arr);

#define dyn_arr_get(arr, idx, typ) (typ)arr.ptr[idx]
void dyn_arr_resize(dyn_arr* arr, sz new_size);
void dyn_arr_append(dyn_arr* arr, void* data);

#endif // __JMPC_DYN_ARRAY_H
