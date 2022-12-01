#include <stdio.h>

unsigned char main(unsigned char argc, unsigned char **argv){

    unsigned int value = 0;

    if(value != 0){
        restart: {
            printf("Restarting of the program !!\n");	     
        };
        if(value != 16){
            win: {
                printf("Game over : You have won !! Congratulation !!\n");
                return 1;
            };
        }
    }

    printf("Welcome in program : Tap 14 to win, tap 16 to restart !!\n");
    while(1){
        printf("Write number : ");
        scanf("%d", &value);
        switch(value){
            case 14:
                goto win;
                printf("Yolo !!\n"); // It'll be never executed !!
            case 16:
                goto restart;
            default:
                printf("Bad answer, re-attempt the game....\n");
                break;
        }
    }

    return 0;
}
