#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int __clearArray(unsigned char **array, unsigned char c){
  if(c <= 0){
    c = DEFAULT_CHARACTER;
  }
  int e, a;
  for(e = 0; e < __lenArray(array); e++){
    for(a = 0; a < __len(array[e]); a++){
      array[e][a] = c;
    }
  }
  return FALSE;
}
