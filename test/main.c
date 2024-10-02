#include <stdio.h>

#include <jmp.h>

int main( void ) {
  rbuf_t *buf = rbuf_new(16, 4);
  
  int a = 13;
  int b = 255;
  
  rbuf_write(buf, (void*)a);
  rbuf_write(buf, (void*)b);
  
  printf("%d\n", rbuf_read(buf, int));
  printf("%d\n", rbuf_read(buf, int));
  
  return 0;
}
