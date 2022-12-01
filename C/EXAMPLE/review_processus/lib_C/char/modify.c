#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int __clear(unsigned char *str, unsigned char c){
  if(c <= 0){
    c = DEFAULT_CHARACTER;
  }
  int e;
  for(e = 0; e < __len(str); e++){
    str[e] = c;
  }
  str[e] = 0;

  return FALSE;
}

int __change(unsigned char *str0, unsigned char *str1){
  int LEN = __len(str1);
  if(__len(str0) < LEN){
    return ERROR;
  }
  int e;
  for(e = 0; e < __len(str0); e++){
    if(e < LEN){
      str0[e] = str1[e];
    }
    else{
      str0[e] = DEFAULT_CHARACTER;
    }
  }
  str0[e] = 0;
  
  return FALSE;
}

int __append(unsigned char *str, unsigned char c){
  int LEN = __len(str);
  if(LEN == 0){
    return ERROR;
  }
  unsigned char *chain = __define(chain, LEN, 1);
  __change(chain, str);
  free(str);
  str = __define(chain, LEN + 1, 1);
  __change(str, chain);
  str[LEN] = c;
  free(chain);
  return FALSE;
}

int __replace(unsigned char *str0, unsigned char *str1, unsigned char *str2, int start, int stop){
  int location = __index(str0, str1, start, stop);
  if(location == -1){
    return NOTHING;
  }
  int e = 0;
  while(e < __len(str1)){
    str0[location+e] = str2[e];
    e++;
  }
  return FALSE;
}

int __replaceAll(unsigned char *str0, unsigned char *str1, unsigned char *str2){
  int err;
  do{
    err = __replace(str0, str1, str2, 0, 0);
  }while(err != NOTHING);
  return FALSE;
}

/*
int main(void){

  unsigned char *w = 0;
  w = __define(w, 5, 1);
  __change(w, "aaaaa");
  printf("[ %s ]\n", w);

  __append(w, 'e');
  __append(w, 'e');

  printf("[ %s ]\n", w);

  free(w);

  return 0;
}
*/
