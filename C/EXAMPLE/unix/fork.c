#include <stdio.h>
#include <unistd.h>

int main(void){

  int val = 15;
  int *p = &val;
  *p = 16;

  short int id0 = fork();
  short int id1 = fork();

  if((id0 == 0) && (id1 == 0)){
    printf("It the child-child processus\n");
  }
  if((id0 == 0) && (id1 != 0)){
    printf("It the child-main processus\n");
  }
  if((id0 != 0) && (id1 == 0)){
    printf("It the main-child processus\n");
  }
  if((id0 != 0) && (id1 != 0)){
    printf("It the main-main processus\n");
  }

  usleep(1000000);

  return 0;
}
