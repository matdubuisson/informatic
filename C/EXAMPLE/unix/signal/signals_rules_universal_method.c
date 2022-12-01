#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void stop_SIGINT(int sig){
  printf("\nWrite a number : ");
  fflush(stdout);
  return;
}

int main(void){

  struct sigaction s;
  s.sa_handler = &stop_SIGINT;
  s.sa_flags = SA_RESTART;
  sigaction(SIGINT, &s, NULL);

  int e;
  printf("Write a number : ");
  scanf("%d", &e);
  printf("\n");

  return 0;
}
