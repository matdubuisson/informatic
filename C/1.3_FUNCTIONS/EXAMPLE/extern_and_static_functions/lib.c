#include <stdio.h>

#include "lib.h"
#ifndef LIB_H
    #error lib.h is not defined !!
#endif

// By default, it's an external global variable
unsigned int nbr0 = 14;
// Like :
extern unsigned int nbr1 = 16;
// But :
static unsigned int nbr2 = 22;

// By default, it's an external function
void print_static_number(void){
    printf("==> %d\n", nbr2);
    return;
}

static unsigned int square_number(unsigned int nbr){
    return nbr * nbr;
}

extern unsigned int *square_list_and_copy(unsigned int *list){
    unsigned int new_list[LIST_LENGTH];
    for(unsigned int i = 0; i < LIST_LENGTH; i++){
        *(new_list + i) = square_number(*(list + i));
    }
    return new_list;
}

