#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(unsigned char argc, unsigned char **argv){

  int fp[2];
  if(pipe(fp) == -1){
    return 1;
  }

  short int id = fork();

  long int e;

  if(id == 0){
    e = 55555;
    close(fp[0]);
    if(write(fp[1], &e, sizeof(long int)) == -1){
      return 2;
    }
    close(fp[1]);
    if(read(fp[0], &e, sizeof(long int)) == -1){
      return 3; // It doesn't work because a pipe cans do only one way
    }
    printf("Child has received %ld\n", e);
    close(fp[0]);
  }
  else{
    close(fp[1]);
    if(read(fp[0], &e, sizeof(long int)) == -1){
      return 4;
    }
    printf("Main has received %ld\n", e);
    e *= 10;
    close(fp[0]);
    if(write(fp[1], &e, sizeof(long int)) == -1){ 
      return 5; // It doesn't work because a pipe cans do only one way
    }
    close(fp[1]);
  }

  return 0;
}
