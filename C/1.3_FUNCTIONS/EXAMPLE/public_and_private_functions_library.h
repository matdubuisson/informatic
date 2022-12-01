#include <stdio.h>

extern void publicFunction(signed int nbr){
    printf("Public => %d\n", nbr);
    return;
}

static void privateFunction(signed int nbr){
    printf("Private => %d\n", nbr);
    return;
}
