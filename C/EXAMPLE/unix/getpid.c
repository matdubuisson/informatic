#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){

  printf("Process id of this progam is %d and process id of the terminal is %d\n", getpid(), getppid());
  printf("View : sudo ps -auwx\n");

  int id = fork();
  if(id == 0){
    printf("My parent is %d and I'm %d\n", getppid(), getpid());
  }
  else{
    wait(0);
    printf("I'm the parent (%d) and the terminal is %d\n", getpid(), getppid());
    int error = wait(0);
    if(error == -1){
      printf("There isn't child to wait !!\n");
    }
  }

  return 0;
}
