#include <stdio.h>

#include "head.h"

char universalVariable;

void printUniversalVariable(void){
  // this function is able to print an input value of main.c
  printf("universalVariable = %d\n", universalVariable);
  return;
}
