#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STDIN 0
#define STDOUT 1

int main(void){
  int p[2];
  char *argv[2];
  argv[0] = "wc";
  argv[1] = 0;
  pipe(p);
  if(fork() == 0) {
    close(STDIN); //CHILD CLOSING stdin
    dup(p[STDIN]); // copies the fd of read end of pipe into its fd i.e 0 (STDIN)
    close(p[STDIN]);
    close(p[STDOUT]);
    execlp("ls", "ls", "-l", NULL);
  } else {
    write(p[STDOUT], "hello world\n", 12);
    close(p[STDIN]);
    close(p[STDOUT]);
  }
  return 0;
}
