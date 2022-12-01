#include <stdio.h>
#include <errno.h>

#include <unistd.h> // write(), read(), close()
#include <fcntl.h> // open()

#include <sys/stat.h> // mkfifo()

#define FILE_NAME "fifoFile"
#define FILE_PERMISSION 0777
// It's the permition as [ sudo chmod 777 ]

#define MESSAGE "Salut comment ca va ?\n"

int len(unsigned char *chain){
  int e = 0;
  while(chain[e] != 0){
    e++;
  }
  return e;
}

int main(char argc, unsigned char **argv){

  if(mkfifo(FILE_NAME, FILE_PERMISSION) == -1){
    if(errno != EEXIST){
      printf("Unknown error so closing of the program...\n");
      return 1;
    }
    printf("File is already created !!\n");
  }

  printf("Opening... It waits a persual...\n");
  int f = open(FILE_NAME, O_WRONLY);
  printf("F = [ %d ]\n", f);
  printf("The file has been read !!\n");
  unsigned char *word = MESSAGE;
  for(int e = 0; e < len(word); e++){
    if(write(f, &word[e], sizeof(char)) == -1){
      printf("Error during the writing, closing of the program...\n");
      return 2;
    }
  }
  close(f);

  return 0;
}
