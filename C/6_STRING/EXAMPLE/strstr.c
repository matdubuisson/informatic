#include <stdio.h>
#include <string.h>

unsigned int main(void){

    unsigned char *sentence = "Bonjour je suis Charlie Chaplin !!";
    unsigned char *string = "our j";
    unsigned char *string2 = "racteur";

    unsigned char *p;
    if((p = strstr(sentence, string)) == NULL){
        printf("String not found !!\n");
    }
    else{
        printf("String found at index : %ld\n", p - sentence);
    }

    if((p = strstr(sentence, string2)) == NULL){
        printf("String2 not found !!\n");
    }
    else{
        printf("String2 found at index : %ld\n", p - sentence);
    }

    return 0;
}
