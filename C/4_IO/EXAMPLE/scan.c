#include <stdio.h>

unsigned char main(void){

    unsigned int number_of_variable_assignments;
    signed int a, b, c;
    printf("What a ? "); scanf("%d" ,&a);
    printf("%d\n", a);
    for(unsigned char i = 0; i < 3; i++){
        // Multi scan
        printf("What are a, b and c ? "); scanf("%d %d %d", &a, &b, &c);
        printf("%d %d %d\n", a, b, c);
    }

    unsigned char chr; unsigned int nbr, count;
    for(unsigned char i = 0; i < 3; i++){
        // Mix scan with %c%d
        printf("What are chr and nbr ? "); count = scanf("%c%d", &chr, &nbr);
        if(count){
            printf("nbr = %d; chr = [%c]\n", nbr, chr);
        }
        else{
            while(getchar() != 10);
        }
    }


    for(unsigned char i = 0; i < 3; i++){
        // Mix scan %d%c
        printf("What are nbr and chr ? "); count = scanf("%d%c", &nbr, &chr);
        if(count){
            printf("nbr = %d; chr = [%c]\n", nbr, chr);
        }
        else{
            while(getchar() != 10);
            printf("Warning, error : Pay attention with this scan when you enter integer with character. Don't let any spaces between both !!\nSee page 391 of my manual !!\n");
        }
    }

    return 0;
}
