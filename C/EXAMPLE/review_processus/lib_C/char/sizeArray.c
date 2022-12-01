#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int __lenArray(unsigned char **array){
  int e = 0;
  while(array[e] != 0){
    e++;
  }
  return e;
}

unsigned char **__defineArray(unsigned char **array, int array_size, int strs_size, int arrayIsEmpty){
  if(!arrayIsEmpty){
    free(array);
  }
  unsigned char **new = malloc(sizeof(char)*(array_size+1)*strs_size);

  int e, a;
  for(e = 0; e < array_size; e++){
    unsigned char *newStr = __define(newStr, strs_size, EMPTY);
    new[e] = newStr;
  }
  new[e] = 0;

  return new;
}

int __freeArray(unsigned char **array){
  for(int e = 0; e < __lenArray(array); e++){
    free(array[e]);
  }
  free(array);
  return FALSE;
}

