#include <stdio.h>

#include <jmp.h>

int main( void ) {
  color_t col = Color_hsv(278, 47, 89);
  
  u8 r = Chanel_to_u8(col.r);
  u8 g = Chanel_to_u8(col.g);
  u8 b = Chanel_to_u8(col.b);
  
  printf("Color :: %u %u %u\n", r, g, b);
  
  return 0;
}
