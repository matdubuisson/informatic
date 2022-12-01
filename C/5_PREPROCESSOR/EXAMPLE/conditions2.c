#include <stdio.h>
#include "PI.h"

//#define VALUE 14
#define VALUE 16

unsigned char main(void){

    #if VALUE == 14 || defined(PI)
        printf("Condition 0 !!\n");
    #else
        printf("VALUE != 14 and PI isn't defined. Change VALUE or include PI.h !!\n");
    #endif

    #if VALUE == 16
        printf("Condition 1 !!\n");
    #endif

    return 0;
}
