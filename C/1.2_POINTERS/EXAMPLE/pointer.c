#include <stdio.h>

void increment_int_var(unsigned int *var){
    (*var)++;
    /*
    Need brackets because (*var)++ != * (var++)
    => In the first case, it accesses to the data and increments
    the value
    => In the second case, it increments the address and accesses
    to the value
    */
    return;
}

void print_address_var(void *var){
    // The pointer (void *) is an universal pointer that can
    // point all types of variables
    
    //*var = 2; // This expression will be rejected because it isn't an appropriate
    // use of the (void *) pointer

    printf("Address : %p\n", var);

    return;
}

unsigned char main(unsigned char argc, unsigned char **argv){

    unsigned int count0 = 0;
    float count1 = 0;

    unsigned char i = 0;
    for(i = 0; i < 10; i++){
        increment_int_var(&count0);
        printf("=> %d\n", count0);
    }

    for(i = 0, count0 = 0; i < 10; i++){
        print_address_var(&count0);
        print_address_var(&count1);
    }

    unsigned int *pointer_count0 = NULL; // This tag is present in stdio.h, stdlib.h and stddef.h. It's the equivalent of 0
    // Or : unsigned int *pointer_count0 = 0;
    pointer_count0 = &count0;

    count0 = 0;
    for(i = 0; i < 5; i++){
        *pointer_count0 += 5; // Same than count0 += 5
         printf("%d == %d\n", count0, *pointer_count0);
    }

    return 0;
}
