#include <stdio.h>
#include <stdlib.h>

#define LEN 400

int main(void){
  printf("SIZE = %ld\n", sizeof(char));
  unsigned char *longChain = malloc(sizeof(char) * LEN);
  char Switch = 1;
  for(int e = 0; e < LEN - 1; e++){
    if(Switch){
      longChain[e] = 48; // = "0"
      Switch = 0;
    }else{
      longChain[e] = 49; // = "1"
      Switch = 1;
    }
  }
  printf("%s\n", longChain);
  free(longChain);
//  printf("%c\n", longChain[140]); // Returns an error because the chain is free now !!
  return 0;
}
