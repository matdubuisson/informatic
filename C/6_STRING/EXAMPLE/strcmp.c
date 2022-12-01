#include <stdio.h>
#include <string.h>

#define size 40

unsigned int main(void){

    unsigned char string[size];    
    strncpy(string, "a b c d e", sizeof(unsigned char) * size);

    if(strcmp(string, "a b c d e") == 0){
        printf("Equal 0 !!\n");
    }
    else{
        printf("Not equal 0 !!\n");
    }

    if(strncmp(string, "dosdosjo", sizeof(unsigned char) * size) == 0){
        printf("Equal 1 !!\n");
    }
    else{
        printf("Not equal 1 !!\n");
    }

    return 0;
}
