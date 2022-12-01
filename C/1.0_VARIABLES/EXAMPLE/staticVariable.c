#include <stdio.h>

void count(void){
  // The function cans remember of the last value of its local variable
  static unsigned char e = 0;
  printf("static e = %d\n", e);
  e++;
}

int main(void){

  count();
  count();
  count();
  count();
  count();

  return 0;
}
