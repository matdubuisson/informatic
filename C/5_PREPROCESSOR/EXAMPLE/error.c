#include <stdio.h>

#define TEST
#ifndef TEST
    #error Never executed !!
#endif

#error This is an error !!

unsigned char main(void){

    printf("Yolo !!\n");

    return 0;
}
