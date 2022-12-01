#include "lib_C/char/lib.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STR_SIZE 40

int Write(int p[2], unsigned char *word){
  close(p[0]);
  char c;
  for(int e = 0; e < __len(word); e++){
    c = word[e];
    if(write(p[1], &c, sizeof(char)) == -1){
      return -1;
    }
  }
  close(p[1]);
  return 0;
}

int Read(int p[2], unsigned char *word){
  close(p[1]);
  char c;
  for(int e = 0; e < __len(word); e++){
    if(read(p[0], &c, sizeof(char)) == -1){
      return -1;
    }
    word[e] = c;//__append(word, c);
  }
  close(p[0]);
  return 0;
}

int main(unsigned char argc, unsigned char **argv){

  printf("Start of the program...\n");

  int fp[2];
  if(pipe(fp) == -1){
    printf("Error with pipe()...\n");
    return 1;
  }

  int id = fork();

  if(id == 0){
    Write(fp, "Salut");
  }
  else{
    unsigned char w[40];
    Read(fp, w);
    printf("[ %s ]\n", w);
  }
  return 0;
}
