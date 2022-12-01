#include <stdio.h>

#define size 30

unsigned char main(void){

    unsigned char i;
    unsigned char name[size];
    for(i = 0; i < size; i++){
        *(name + i) = 0;
    }
    printf("What is your name ? ");
    unsigned char chr = 0;
    i = 0;
    do{
        chr = getchar();
        *(name + i) = chr;
        i++;
    }while(chr != 10);

    printf("==> %s", name);

    return 0;
}
