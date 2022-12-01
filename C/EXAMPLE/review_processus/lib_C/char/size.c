#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int __len(unsigned char *str){
  int e = 0;
  while(str[e] != 0){
    e++;
  }
  return e;
}

/////////////////////////////////////////////////////

unsigned char *__define(unsigned char *str, int size, int strIsEmpty){
  if(!strIsEmpty){
    free(str); // Clean the last str, this permits to free the alloced memory
  }
  size++; // size + 1 for chain+0 either end character
  if(size < 0){ // Not possible
    return FALSE;
  }
  unsigned char *chain = malloc(sizeof(char) * size);
  int e;
  for(e = 0; e < size - 1; e++){
    chain[e] = DEFAULT_CHARACTER;
  }
  chain[e] = 0;
  return chain;  // After deleting the old chain, it's returns the new chain
}

////////////////////////////////////////////////////////////////
