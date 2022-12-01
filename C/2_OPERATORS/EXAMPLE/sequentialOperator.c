#include <stdio.h>

int main(void){

  unsigned char a = 9, b = 5, c = 7; // OR : int a = 9; int b = 5; int c = 7;
  a = 19, b = 15, c = 17; // a = 19; b = 15; c = 17;

  for(int e = 0; e < 5; e++){
    printf("E = %d\n", e);
  }
  // Same than :
  for(int e = 0; e < 5; e++){
    printf("E = %d\n", e);
  }

  b++, c -= 3;
  a = 0;
  unsigned char working = 1;
  while((a < 9 ? a += 2 : working--) && (working ? 1 : 0)){
    printf("A = %d\n", a);
  }

  printf("End of the program ...\n");

  return 0;
}
