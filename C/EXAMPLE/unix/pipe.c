#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){
  int fp[2]; // Kind of file with pipe
  /*

    fp[0] => reading
    fp[1] => writing

  */

  if(pipe(fp) == -1){
    printf("Error with the beginning of the new pipe...\n");
    return 1;
  }

  short int id = fork();
  if(id == 0){
    close(fp[0]); // By security it closes the reading
    int nbr;
    printf("Put number to send to the parent process [ %d ] : ", getppid());
    scanf("%d", &nbr);
    printf("\n");
    write(fp[1], &nbr, sizeof(int)); // When it uses fp[1], it automatically opens the writing
    close(fp[1]); // So it askes to close the writing
  }
  else{
    close(fp[1]); // By security it closes the writing
    int nbr;
    read(fp[0], &nbr, sizeof(int));
    close(fp[0]);
    printf("I'm the parent process [ %d ] and I have received from child process the integer number : %d\n", getpid(), nbr);
  }

  return 0;
}
