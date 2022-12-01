#include <stdio.h>
#include "PI.h"

unsigned char main(void){

    #ifdef __FILE__
        printf("The macro __FILE__ is defined !!\n");
    #else
        printf("The macro __FILE__ isn't defined !!\n");
    #endif

    #ifndef J_EXISTE_PO
        printf("The macro J_EXISTE_PO isn't defined !!\n");
    #endif

    #ifndef PI
        #define PI 2.27
    #else
        printf("The macro PI is already defined !!\n");
    #endif

    printf("PI = %f\n", PI);

    return 0;
}
