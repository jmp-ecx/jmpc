#include <jmp/dbg.h>
#include <jmp.h>

#include <stdio.h>

void *jmp_dbg_malloc(sz size, const char *FILE, const int LINE) {
  printf("Allocating %lld bytes in %s :: %d\n", size, FILE, LINE);
  
  void* ptr = malloc(size);
  if (!ptr) printf("No memory for allocation\n");
  
  return ptr;
}

void  jmp_dbg_free(void* ptr, const char *FILE, const int LINE) {
  printf("Freeing allocation in %s :: %d\n", size, FILE, LINE);
  free(ptr);
}
