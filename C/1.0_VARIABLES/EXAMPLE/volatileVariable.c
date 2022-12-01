#include <stdio.h>

int main(void){
  volatile int e = 0;
  e++;
  printf("%d\n", e);
  while(e < 10000){
    e++;
  }
  printf("%d\n", e);
  return 0;
}
