#include <stdio.h>

unsigned char main(void){

    unsigned int number, count;
    do{
        printf("Number : ");
        count = scanf("%d", &number); // int(input())
        if(count){
            printf("!Number = %d\n", !number);
            printf("Number**2 = %d\n", number * number);
        }
        else{
            // Defensive part
            while(getchar() != 10); // while getchar() != '\n'
        }
        printf("Count = %d\n", count);
    }while(number); // while number != 0

    return 0;
}
