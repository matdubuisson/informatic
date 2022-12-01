#include <stdio.h>
#include <string.h>

#define size 40
#define show printf("%s <=> %s\n%ld <=> %ld\n", str0, str1, strlen(str0), strlen(str1))

void init(unsigned char *str){
    static unsigned int i;
    for(i = 0; i < size - 1; i++){
        *(str + i) = 33; // '!'
    }
    *(str + i) = 0; // Important !!
    return;
}

unsigned int main(void){

    unsigned char str0[size];
    unsigned char str1[size];

    init(str0); init(str1);
    show;

    strcpy(str0, "Racteur");
    show;
    strcpy(str1, str0);
    show;
    strcpy(str0, "Computer Science is so cool !!");
    show;

    unsigned char str2[size - 10];
    // Versus strcpy(), strncpy() can avoid the overtaking of copying
    strncpy(str2, str0, sizeof(unsigned char) * (size - 10));
    show;
    printf("==> %*s\n", size - 10, str2);

    return 0;
}
