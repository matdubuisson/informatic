#include <stdio.h>

#define size 10

unsigned char main(unsigned char argc, unsigned char **argv){

    unsigned int array[size + 1];
    unsigned int i;
    for(i = 0; i < size; i++){
        array[i] = i*i;
    }
    array[i] = '\0';

    /*
    In fact, the operator [] can be replaced with the operator * with () !!
    array == &array[0] == *(array + 0)
    &array[1] == *(array + 1)
    &array[2] == *(array + 2)
    &array[i] == *(array + i)
    */

    for(i = 0; i < size; i++){
        printf("%d\n", *(array + i));
    }

    return 0;
}
