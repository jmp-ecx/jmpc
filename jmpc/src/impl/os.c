#include <jmp/os.h>

int flen(FILE *fptr) {
  int size;
  
  fseek(fptr, 0L, SEEK_END);
  size = ftell(fptr);
  rewind(fptr);
  
  return size;
}
