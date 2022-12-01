#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv){

  int id = fork();
  printf("Yolo from id : %d\n", id);
  if(id == 0){
    printf("It's the child process...\n");
  }else{
    printf("It's the main process...\n");
  }

  int id2 = fork();
  printf("Yolo from id2 : %d\n", id2);
  if((id == 0) && (id2 == 0)){
    printf("It's the child_child...\n");
  }
  if((id == 0) && (id2 != 0)){
    printf("It's the child_main...\n");
  }
  if((id != 0) && (id2 == 0)){
    printf("It's the main_child...\n");
  }
  if((id != 0) && (id2 != 0)){
    printf("It's the main_main...\n");
  }


  return 0;
}
