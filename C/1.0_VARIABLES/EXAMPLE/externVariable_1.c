#include <stdio.h>

#include "externVariable_head.h"

void fct1(void){
  printf("From fct1 : e = %d\n", e);
  e++;
}
