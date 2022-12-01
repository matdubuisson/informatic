#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){
  printf("What is the waited pid ? ");
  int pid;
  scanf("%d", &pid);
  printf("\n");

  int wstatus;
  waitpid(pid, &wstatus, 0);
  printf("FINISHED\n");
  if(WIFEXITED(wstatus)){
    int status = WEXITSTATUS(wstatus);
    printf("The processus has exited %d !!\n", status);
  }
  return 0;
}
