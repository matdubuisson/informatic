#include <stdio.h>

#undef __FILE__
#define __FILE__ "Yolo !!\n"

unsigned char main(void){

    printf(__FILE__);

    unsigned int var = 16;
    
    #define var 14
    printf("=> %d\n", var);

    #undef var
    printf("=> %d\n", var);

    return 0;
}
