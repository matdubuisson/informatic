#include <stdio.h>
#include <unistd.h>

int main(void){
  printf("PID = %d\n\n", getpid());
  int e = 0;
  while(1){
    printf("WHILE...\n");
    usleep(500000);
    printf(" WHILE[%d]...\n", e);
    usleep(500000);
    e++;
  }
  return 0;
}
