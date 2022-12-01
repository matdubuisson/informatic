#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

/*
| => Combine action
O_CREAT : Create file
O_WRONLY : Write only file
O_RDONLY : Read only file
O_RDWR : Read and write file
*/

#define size 30

unsigned int main(unsigned int argc, unsigned char **argv){

    unsigned int i, fd;

    fd = open("test.txt", O_CREAT | O_WRONLY); // From fcntl.h

    unsigned char name[size];
    strncpy(name, "This is a smart string !!", size);
    for(i = 0; i < size; i++){
        write(fd, (name + i), 1); // Write one character each time in the file
    }

    close(fd);

    fd = open("test.txt", O_RDONLY);

    unsigned char name2[size];
    strncpy(name2, "", size);
    for(i = 0; i < size; i++){
        read(fd, (name2 + i), 1); // Read one character each time in the file
    }

    close(fd);

    // strcmp returns 0 when both are equal
    if(!strncmp(name, name2, size)){
        printf("The two strings are equal !!\n");
    }
    else{
        printf("The strings are different....\n'%s' != '%s'\n", name, name2);
    }

    return 0;
}
