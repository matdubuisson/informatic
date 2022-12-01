#include <stdio.h>

#define len 40
char message[len + 1] = "This message is from a pipe !!";

int main(void){

  int p[2];
  int pipe(int [2]);

  if(pipe(p) == -1){
    printf("Error in the creation of the pipe !!\n");
    return 1;
  }

  if(fork() == 0){
    char c;
    close(p[1]);
    while(read(p[0], &c, 1) != 0){
      printf("%c", c);
    }
    printf("\n");
    close(p[0]);
    return 0;
  }
  else{
    close(p[0]);
    write(p[1], message, len);
    close(p[1]);
    return 0;
  }
  return 0;
}
