#include <stdio.h>
#include <stdlib.h> // system()
#include <unistd.h> //
#include <sys/wait.h>
#include <fcntl.h>

#define FILE_NAME "log.txt"
#define FILE_PERM 0777

int main(void){

  int pid = fork();
  if(pid == -1){
    return 1;
  }

  if(pid == 0){
    // CHILD
    int f = open(FILE_NAME, O_WRONLY | O_CREAT, FILE_PERM);
    if(f == -1){
      return 2;
    }

    int f2 = dup2(f, 1);
    int err = execlp("ls", "ls", "-l", NULL);
    if(err == -1){
      return 3;
    }
    printf("This message is in the log.txt and it has removed the first sentence of the result of ls -l !!\n");
    close(f);
  }
  else{
    int err = wait(NULL);
    if(err == -1){
      return 4;
    }
    printf("Closing of the program...\n");
  }
  return 0;
}
