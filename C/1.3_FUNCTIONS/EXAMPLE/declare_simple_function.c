#include <stdio.h>

unsigned int fct0(void);

unsigned int fct1(void){
    return 16;
}

void prFct(signed int); // Or : void prFct(signed int nbr);

unsigned char main(unsigned char argc, unsigned char **argv){
    unsigned int fct2(void);
    prFct(fct0());
    prFct(fct1());
    prFct(fct2());
    signed int var = 0;
    prFct(var = (signed int) (fct0() + fct1() + fct2()));
    printf("var ==> %d\n", var);


    return 0;
}

unsigned int fct0(void){
    return 14;
}

void prFct(signed int nbr){
    printf("prFct => %d\n", nbr);
    return;
}

unsigned int fct2(void){
    return 14 + 16;
}
