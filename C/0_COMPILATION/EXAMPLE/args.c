#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_list(unsigned char **list);

unsigned int main(unsigned char opt_c, unsigned char **opt){

    read_list(opt);

    return 0;
}

void read_list(unsigned char **list){
    static unsigned int i;
    i = 0;
    while(*(list + i) != 0){
        printf("%s\n", *(list + i));
        i++;
    }
    return;
}

