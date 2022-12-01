#include <stdio.h>

int main(void){

  signed int a = 2000;
  unsigned int b = 10;
  signed int sRes = a + b;
  unsigned int usRes = a + b;

  printf("sRes = %d\n", sRes);
  printf("usRes = %d\n", usRes);

//  usRes = (signed int) usRes; // The compilator does it itself !!
  usRes -= 3000;

  printf("usRes = %d\n", usRes);

  return 0;
}
