#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define udelay 100000
#define del_chr 8

void print_chararacter_with_flush(unsigned char chr){
    write(1, &chr, sizeof(unsigned char));
    return;
}

unsigned int main(void){

    unsigned int i;

    // For sleep() : unsigned int sleep(unsigned int seconds);
    // For usleep() : int usleep(useconds_t usec);

    printf("Starting of the program...\n");
    for(i = 0; i < 6; i++){
        print_chararacter_with_flush('|');
        usleep(udelay);
        print_chararacter_with_flush(del_chr);
        print_chararacter_with_flush('/');
        usleep(udelay);
        print_chararacter_with_flush(del_chr);
        print_chararacter_with_flush('-');
        usleep(udelay);
        print_chararacter_with_flush(del_chr);
        print_chararacter_with_flush('\\');
        usleep(udelay);
        print_chararacter_with_flush(del_chr);
    }

    return 0;
}
