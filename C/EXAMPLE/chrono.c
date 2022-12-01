#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int returnIntegerNumber(unsigned char *argvv){
  int nbr = 0;
  int e = 0;
  while(argvv[e] != 0){
    if((argvv[e] >= 48) && (argvv[e] <= 57)){
      nbr += (argvv[e] - 48) + (10 * e);
      e++;
    }
    else{
      return -1;
    }
  }
  return nbr;
}

int main(unsigned char argc, unsigned char **argv){
  printf("PID = %d\n", getpid());
  if(argc != 3){
    printf("Bad arguments... Please try by example [ %s integer exitedInteger ]\n", argv[0]);
    return 1;
  }
  int nbr = returnIntegerNumber(argv[1]);
  if(nbr == -1){
    printf("Bad count...\n");
    return 2;
  }
  printf("[ %d ]\n", nbr);
  for(int e = 0; e < nbr; e++){
    usleep(1000000);
  }
  return returnIntegerNumber(argv[2]);
}
