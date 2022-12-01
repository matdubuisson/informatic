#include <stdio.h>

void print_pointer(void){

    static unsigned int stVar = 4;
    printf("var : %d\n", stVar);
    stVar += 2;

    return;
}

unsigned char main(unsigned char argc, unsigned char **argv){

    for(unsigned char i = 0; i < 14; i++){
        print_pointer();
    }

    return 0;
}
