#include <stdio.h>

int main(void){
  int e = 0, a = 4;
  e = a = 6;
  printf("e = a = 6 : e = %d and a = %d\n", e, a);

  e = 14 + (a = 2);
  printf("e = 14 + (a = 2) : e = %d and a = %d\n", e, a);

  return 0;
}
