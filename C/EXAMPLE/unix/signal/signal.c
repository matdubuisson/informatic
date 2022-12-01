#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(void){

  int pid = fork();

  if(pid == 0){
    printf("Do you want to destroy main ? Write 1\n");
    int e;
    while(e != 1){
      scanf("%d", &e);
    }
    kill(getppid(), SIGKILL); // Kill main (info : getppid() == pid of parent processus)
  }
  else{
    sleep(4);
    while(1){
      printf("MAIN\n");
      usleep(500000);
    }
  }

  printf("A processus finished !!\n"); // Main won't be able to execute this line so
                                       // the line will be present only once

  return 0;
}
