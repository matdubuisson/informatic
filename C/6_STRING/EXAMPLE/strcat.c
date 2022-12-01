#include <stdio.h>
#include <string.h>

#define size 100
#define show printf("=> %s\n=> %s\n=> %s\n", str0, str1, str2);

unsigned int main(void){

    unsigned char str0[size];
    unsigned char str1[size];
    unsigned char str2[size];

    strncpy(str0, "Bonsoir ", sizeof(unsigned char) * size);
    strncpy(str1, "Racteur ", sizeof(unsigned char) * size);
    strncpy(str2, "==> ", sizeof(unsigned char) * size);
    show

    strcat(str2, str0);
    strcat(str2, str1);
    show

    strcat(str0, strcat(str0, str2));
    //strcat(str0, strcat(str0, str0)); // Produce : Segmentation fault (core dumped)
    show

    // So there is a way to avoid the memory overtaking
    strncat(str0, strncat(str0, str0, sizeof(unsigned char) * size), sizeof(unsigned char) * size); // Does nothing because it overtakes the limit

    return 0;
}
