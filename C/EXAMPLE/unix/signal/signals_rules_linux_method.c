#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void stop_SIGINT(int sig){
  printf("\nWrite a number : ");
  fflush(stdout);
  return;
}

int main(void){

  signal(SIGINT, &stop_SIGINT);

  int e;
  printf("Write a number : ");
  scanf("%d", &e);
  printf("\n");

  return 0;
}
