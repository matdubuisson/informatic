#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int __printArray(unsigned char **array){
  int e, a;
  printf("[ ");
  for(e = 0; e < __lenArray(array); e++){
    for(a = 0; a < __len(array[e]); a++){
      printf("%c", array[e][a]);
    }
    printf(", ");
  }
  printf("0 ]\n");
  return FALSE;
}

