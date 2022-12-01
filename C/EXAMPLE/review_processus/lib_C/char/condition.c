#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int __equal(unsigned char *str0, unsigned char *str1){
  int LEN = __len(str0);
  if(LEN != __len(str1)){
    return FALSE;
  }
  for(int e = 0; e < LEN; e++){
    if(str0[e] != str1[e]){
      return FALSE;
    }
  }
  return TRUE;
}

int __find(unsigned char *str0, unsigned char *str1){
  int LEN = __len(str1);
  char firstCharacter = str1[0];
  int e, a;
  for(e = 0; e < __len(str0); e++){
    if(str0[e] == str1[0]){
      for(a = 1; a < LEN; a++){
        if(str0[e+a] != str1[a]){
          a = LEN;
        }
        if(a+1 == LEN){
          return TRUE;
        }
      }
    }
  }
  return FALSE;
}

int __index(unsigned char *str0, unsigned char *str1, int start, int stop){
  int _LEN = __len(str0);
  int LEN = __len(str1);
  char firstCharacter = str1[0];
  int e, a;
  if((start == 0) && (stop == 0)){
    stop = _LEN;
  }
  if((start < 0) || (stop > _LEN)){
    return ERROR;
  }
  for(e = start; e < stop ; e++){
    if(str0[e] == str1[0]){
      for(a = 1; a < LEN; a++){
        if(str0[e+a] != str1[a]){
          a = LEN;
        }
        if(a+1 == LEN){
          return e;
        }
      }
    }
  }
  return NOTHING;
}
