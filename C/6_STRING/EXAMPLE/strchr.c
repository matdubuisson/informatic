#include <stdio.h>
#include <string.h>

#define size 60

unsigned int main(void){

    unsigned char name[size];
    strncpy(name, "Ceci A est un A test !! A Yolo !!", sizeof(unsigned char) * size);
    printf("==> %s\n", name);


    unsigned char *addr_first_A = strchr(name, 'A');
    unsigned char *addr_last_A = strrchr(name, 'A');

    printf("Index of the first A : %ld\n", addr_first_A - name);
    printf("Index of the last A : %ld\n", addr_last_A - name);

    return 0;
}
