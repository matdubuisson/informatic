#include <stdio.h>

void swap0(signed int *a, signed int *b){
    signed int c = *a;
    *a = *b;
    *b = c;
    return;
}

// ONLY IN C++ :
/*
void swap1(signed int & a, signed int & b){
    signed int c = a;
    a = b;
    b = c;
    return;
}
*/

unsigned char main(unsigned char argc, unsigned char **argv){

    void swap0(signed int *, signed int *);
    //void swap1(signed int &, signed int &);

    signed int x = 16, y = 14;
    printf("%d <=> %d\n", x, y);
    swap0(&x, &y);
    printf("%d <=> %d\n", x, y);
    //swap1(x, y);
    //printf("%d <=> %d\n", x, y);

    return 0;
}
