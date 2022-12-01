#include <stdio.h>

// The execution of the program does the first call of main() !!

unsigned int main(unsigned int argc, unsigned char **argv){

    static signed int i = 10;
    printf("Message from main %d\n", i);
    i -= 1;
    if(i >= 0){
        main(i, NULL);
    }

    return 0;
}
