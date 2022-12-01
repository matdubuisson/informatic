#include <stdio.h>
#include <unistd.h>

#define RUN 1000000000

int main(void){
  int th = fork();
  if(!th){
    register unsigned int long long e = 0; // This variable is really most swift than the second
    while(e < RUN){
      e++;
    }
    printf("Register has finished !!\n"); // It will be the first
  }
  else{
    unsigned int long long e = 0;
    while(e < RUN){
      e++;
    }
    printf("Normal has finished !!\n");
  }
  return 0;
}
