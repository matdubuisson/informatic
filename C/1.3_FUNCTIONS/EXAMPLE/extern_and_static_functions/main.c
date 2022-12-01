#include <stdio.h>

#include "lib.h"

unsigned char main(void){

    unsigned int list[LIST_LENGTH], i;

    for(i = 0; i < LIST_LENGTH; i++){
        *(list + i) = i;
    }

    unsigned int *list2 = square_list_and_copy(list);

    for(i = 0; i < LIST_LENGTH; i++){
        printf("list[%d] = %d\nlist2[%d] = %d\n", i, *(list + i), i, *(list2 + i));
    }

    return 0;
}
