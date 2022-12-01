#include <stdio.h>
#    include <stdlib.h>

// Here, #x is the name of argument and x is the value of this argument;
// So print(z=4) ==> #x = z=4 and x = 4
#define print(x) printf("The variable " #x " is %d !!\n", x)

#define test a ## b ## c
#define concat(a, b) a ## b

unsigned char main(void){

    unsigned int z;
    print(z = 4);
    print(z);
    
    unsigned int abc = 15;
    printf("==> %d\n", test);

    unsigned int x, y, xy;
    concat(x, y) = 4; // Same than : xy = 4;
    print(xy);

    return 0;
}
