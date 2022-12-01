#include <stdio.h>

#include "externVariable_head.h"

unsigned int e = 0; // It askes only on new declaration in a file.c
// Only one is quite enough for all files that includes its library.h
// It needs to be in a global also and not a function (even main()) !!

void fct0(void){
  printf("From fct0 : e = %d\n", e);
  e++;
}

int main(void){

  printf("From main : e = %d\n", e);
  fct0();
  fct1();
  printf("From main : e = %d\n", e);

  return 0;
}
