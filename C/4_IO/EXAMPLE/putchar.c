#include <stdio.h>

unsigned char main(void){

    for(unsigned char c = 32; c < 127; c++){
        putchar(c);
    }; putchar(10);

    /*
        putchar(32); // As printf(" ");
    */
    unsigned int rest;
    for(unsigned char c = 32; c < 35; c++){
        printf("=================\n");
        rest = putchar(c); // Returns an unsigned int number that is the written character (as integer)
        printf("\n%d\n", rest);
    } // Under 32 there are special characters
    putchar(10); // As printf("\n");

    return 0;
}
