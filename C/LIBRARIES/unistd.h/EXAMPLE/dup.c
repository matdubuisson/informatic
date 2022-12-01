#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define STDIN 0
#define STDOUT 1

#define size 100

signed int write_file(signed int fd, unsigned char *line){
    static unsigned int i;
    for(i = 0; i < strnlen(line, size); i++){
        if(write(fd, (line + i), 1) == -1){
            printf("Error with writing !!\n");
            return -1;
        }
    }
    return 0;
}

signed int read_file(signed int fd, unsigned char *line, unsigned int count){
    static unsigned int i;
    static unsigned char chr;
    i = 0;
    while(i < count){
        if(read(fd, &chr, 1) == -1){
            printf("Error with reading !!\n");
            return -1;
        }
        if(chr <= 0){
            break;
        }
        *(line + i) = chr;
        i++;
    }
    return 0;
}

unsigned int main(void){

    signed int fd = open("file.txt", O_CREAT | O_RDWR);

    unsigned char *line = malloc(sizeof(unsigned char) * size), *line2 = malloc(sizeof(unsigned char) * size);

    strncpy(line, "This is a context line to test it !!\nDo you copy that ?\n", size);
    write_file(fd, line);

    close(fd); fd = open("file.txt", O_CREAT | O_RDWR);

    unsigned int length = strnlen(line, size);

    strncpy(line2, "", size);
    read_file(fd, line2, length);
    printf("Line2 = %s\n", line2);

    signed int fd2 = dup(fd);

    lseek(fd, 0, SEEK_SET); // Change seek for fd and fd2;

    strncpy(line, "", size);
    printf("==> [%s]\n", line);
    read_file(fd2, line, length);
    printf("==> [%s]\n", line);

    close(fd); // Close fd but fd2 is always opened !!

    lseek(fd2, 0, SEEK_SET);

    strncpy(line, "", size);
    printf("==> [%s]\n", line);
    read_file(fd2, line, length);
    printf("==> [%s]\n", line);

    close(fd2);

    free(line); free(line2);

    return 0;
}
