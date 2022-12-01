#include <stdio.h>

int main(void){
  int a = 4, b = 5, c = 4;
  int d = !a * 2 == 4;
  int e = !a != 4 && 2 * a == 6;
  int f = a || b && c;
  printf("a = %d; b = %d; c = %d; d = %d; e = %d; f = %d\n", a, b, c, d, e, f);
  return 0;
}
