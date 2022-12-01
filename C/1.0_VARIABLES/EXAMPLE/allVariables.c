#include <stdio.h>

void changeValue(auto unsigned int *address, auto unsigned int newValue){

    *address = newValue;

    return;
}

unsigned char main(unsigned char argc, unsigned char **argv){

    auto unsigned int value = 0;
    printf("==> %ls\n", &value);
    value = 2;
    printf("==> %ls\n", &value);

    changeValue(&value, 14);
    printf("==> %ls\n", &value);

    return 0;
};
