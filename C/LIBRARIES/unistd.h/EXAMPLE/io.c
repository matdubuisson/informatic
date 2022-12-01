#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef STDIN
    #define STDIN 0
#endif
#ifndef STDOUT
    #define STDOUT 1
#endif
#ifndef STDERR
    #define STDERR 2
#endif

#define size 40

void print_word(unsigned char *word){
    static unsigned int i;
    for(i = 0; i < size; i++){
        if(write(STDOUT, (word + i), sizeof(unsigned char)) == -1){
            printf("ERROR WITH WRITE !!\n");
        }
        // Equivalent of :
        //putchar(*(word + i));
    }
    putchar(10);
    return;
}

void scan_word(unsigned char *word){
    static unsigned int i;
    static unsigned char chr;
    for(i = 0; i < size; i++){
        if(read(STDIN, &chr, sizeof(unsigned char)) == -1){
            printf("ERROR WITH READ !!\n");
        }
        // Equivalent of :
        //chr = getchar();
        if(chr == 10){
            break;
        }
        else{
            *(word + i) = chr;
        }
    }
    return;
}

unsigned int main(void){

    unsigned char word[size];
    strncpy(word, "", size);
    printf("Write your word : \n");
    scan_word(word);
    printf("Your word : \n");
    print_word(word);

    return 0;
}
