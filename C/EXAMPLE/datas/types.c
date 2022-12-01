#include <stdio.h>
#include <stdlib.h>

int main(void){

  unsigned long long int e = 4000000000000000000;

  short h = 48;

  char bool = 1;

  printf("[ %ld ]\n", sizeof(e));
  printf("[ %lld ]\n", e);

  unsigned short int a = 35000;

  printf("==> [ %d ]\n", 65000 * 255);

  return 0;
}
