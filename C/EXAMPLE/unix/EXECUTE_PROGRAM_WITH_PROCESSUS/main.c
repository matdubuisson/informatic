#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(unsigned char argc, unsigned char **argv){

  printf("Starting...\n");

/*
  execlp("./cmd", "./cmd", "option", "parameter", NULL);
  printf("The end of the program isn't executed !!\n");
*/

  short int id = fork();

  if(id == 0){
    int err = execlp("./cmd", "./cmd", "option", "parameter", "a", "b", "c", "...", NULL);
    if(err == -1){
      return 6;
    }
    printf("No executed !!\n");
  }
  else{
    int wstatus;
    wait(&wstatus);
    if(WIFEXITED(wstatus)){
      int returnedCode = WEXITSTATUS(wstatus);
      if(returnedCode == 6){
        printf("The command in the child isn't correct...\n");
      }
      if(returnedCode == 0){
        printf("All the process of the child is correct. The program is finished !!\n");
      }
      else{
        printf("Returned number is %d\n", returnedCode);
      }
    } 
    printf("Stopping...\n");
  }
  return 0;
}
