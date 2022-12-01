#include <stdio.h>
#include <string.h>

#define size 40

void init(unsigned char *str){
    static unsigned int i;
    for(i = 0; i < size - 1; i++){
        *(str + i) = 33; // '!'
    }
    *(str + i) = 0; // Important !!
    return;
}

unsigned int main(void){

    // strlen() don't return the memory length but return the string length
    // Count until to read a '\0' character to stop
    // Risk of memory overtaking
    unsigned char name[size];
    printf("=> %ld\n", strlen(name));
    printf("==> [%s]\n", name);

    *(name) = *(name + 1) = 32;
    printf("=> %ld\n", strlen(name));
    printf("==> [%s]\n", name);

    init(name);
    printf("=> %ld\n", strlen(name));
    printf("==> [%s]\n", name);

    // strnlen() can manage this problem
    printf("=> %ld\n", strnlen(name, sizeof(unsigned char) * size));
    printf("==> [%s]\n", name);

    // Even if the last characteur isn't '\0'
    *(name + size - 1) = 33;
    printf("=> %ld\n", strnlen(name, sizeof(unsigned char) * size));
    printf("==> [%s]\n", name);

    return 0;
}
