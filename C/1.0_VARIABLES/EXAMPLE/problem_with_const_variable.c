#include <stdio.h>

unsigned char main(unsigned char argc, unsigned char **argv){

    const unsigned int value = 14;
    //value += 1;
    unsigned int *test = &value;
    printf("%d\n", *test);
    *test += 2;
    printf("%d\n", *test);

    return 0;
}
