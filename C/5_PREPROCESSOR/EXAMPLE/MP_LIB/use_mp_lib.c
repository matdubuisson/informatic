#include <stdio.h>

#include "mp_lib.h"

unsigned char main(void){

    print_word0();
    //print_word1();

    unsigned int var = 4;
    increment(&var);
    printf("Var = %d\n", var);

    //float var2 = 4.0;
    //increment(&var2); // Incorrect
    //printf("Var2 = %f\n", var2); 

    return 0;
}
