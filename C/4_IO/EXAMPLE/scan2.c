#include <stdio.h>

void clean_buffer(void){
    // When it limits scans, it's cool to clean sometimes the buffer !!
    while(getchar() != 10);
}

unsigned char main(void){

    // Limit scan
    unsigned int nbr;
    scanf("%4d", &nbr); printf("==> %d\n", nbr);
    clean_buffer();
    // Not allowed :
    //scanf("%*d", 4, &nbr); printf("==> %d\n", nbr);

    unsigned char name[15];
    scanf("%14s", name); printf("%s\n", name);
    clean_buffer();
    for(unsigned int i = 0; i < 15; i++){
        *(name + i) = 0; // name[i] = 0;
    }
    scanf("%4s", name); printf("%s\n", name);
    clean_buffer();

    // Make separator for scan
    unsigned char chr; unsigned char str[20]; unsigned int intn;
    scanf("%c|%s %d", &chr, str, &intn);
    printf("=> %c\n==> %s\n===> %d\n", chr, str, intn);

    return 0;
}
