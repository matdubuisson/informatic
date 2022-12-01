#include <stdio.h>
#include <stdlib.h> // Where is malloc() and free()

#define _type unsigned int

unsigned char main(void){

    // Method 0 :
    _type p0 = 14;
    printf("p0 = %d\n", p0);

    // Method 1 :
    /*
        *p1 <=> *(p1 + 0) <=> p1[0]
    */
    _type *p1; // sizeof() isn't a function, it's an operator
    p1 = malloc(sizeof(_type));
    *p1 = 16;
    printf("p1 = %d\n", *p1);
    *p1 = 4 * *p1 + 3; // p1 = 4 * 16 + 3
    printf("p1 = %d\n", *p1);
    p1[0] = 17;
    printf("p1 = %d\n", *p1);
    free(p1);

    printf("Size of unsigned int : %d\n", (_type) sizeof(_type));

    return 0;
}
