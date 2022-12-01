#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h> // For open()

#define STDIN 0
#define STDOUT 1
#define STDERR 2

unsigned int main(void){

    // Open a file :
    signed int fd = open("test_dup2.txt", O_CREAT | O_RDWR);

    printf("This line !!\n");

    if(dup2(fd, STDOUT) == -1){
        printf("Error with the redirection of stdout in test_dup2.txt !!\n");
        return -1;
    }

    unsigned char *name = "Retest with string !!\n";
    write(1, name, sizeof(unsigned char) * strlen(name));
    puts("Test\n");
    printf("This line !!\n");
    printf("Yolo !!\n");

    close(fd);

    return 0;
}
