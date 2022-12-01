#include <stdio.h>
#include <unistd.h>

int main(unsigned char argc, unsigned char **argv){

  printf("=====================\n");
  printf("There are %d arguments !!\n", argc);
  char e = 0;
  while(argv[e] != 0){
    printf("ARG[%d] = %s\n", e, argv[e]);
    e++;
  }
  printf("=====================\n");

  for(int e = 0; e < 11; e++){
    printf("Action of the server : %d\n", e);
    usleep(100000);
  }
  return 0;
}
