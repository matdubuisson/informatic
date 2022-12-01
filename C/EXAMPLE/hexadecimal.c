#include <stdio.h>

int main(void){

  /*
    0x88 = [10001000] = 8 + 128 = 136
    0xC7F = [ 110001111111 ] = 2^0 + 2^1 + 2^2 + 2^3 + 2^4 + 2^5 + 2^6 + 2^10 + 2^11
    = 1 + 2 + 4 + 8 + 16 + 32 + 64 + 1024 + 2048 = 127 + 3072 = 3199
    2^7:   2^8:   2^9:   2^10:   2^11:
    128 => 256 => 512 => 1024 => 2048
  */

  printf("[ %d ]\n", 0x88);
  printf("[ %d ]\n", 0xC7F);

  return 0;
}