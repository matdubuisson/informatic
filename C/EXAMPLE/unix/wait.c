#include <stdio.h>
#include <unistd.h>

#include <sys/wait.h>

int main(void){

  short int id = fork();

  if(id == 0){
    for(int e = 0; e < 7; e++){
      printf("CHILD PROCESS %d\n", e);
      usleep(100000);
    }
  }

  if(id != 0){
    printf("MAIN WAITS...\n");
    int status;
    wait(&status);
    printf("STATUS : %d\n", status);
    printf("MAIN HAS WAITED so IT'S CONTINUING NOW !!\n");
    for(int e = 0; e < 5; e++){
      printf("MAIN PROCESS %d\n", e);
      usleep(100000);
    }
  }

  return 0;
}
