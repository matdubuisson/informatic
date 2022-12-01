#include <stdio.h>
#include <stdlib.h> // system()
#include <string.h>
#include <unistd.h> // access(), close()
#include <fcntl.h> // open()
#include <sys/stat.h>

#define file "test_access.txt"
#define size 40

void print_binary(unsigned int nbr){

    static unsigned int digits[size];
    static unsigned int i;
    for(i = 0; i < size; i++){
        *(digits + i) = 0;
    }

    return 0;
}

unsigned int main(void){

    close(open(file, O_CREAT));
    signed int fd;
    unsigned char cmd[size];

    for(unsigned int i = 0; i < 10; i++){
        //fd = access(file, i);
        if(chmod(file, i) == -1){
            printf("Can't chmod at attempt %d\n !!", i);
        }
        strcpy(cmd, "");
        sprintf(cmd, "ls -l | grep %s", file);
        system(cmd);
        //close(fd);
    }

    return 0;
}
