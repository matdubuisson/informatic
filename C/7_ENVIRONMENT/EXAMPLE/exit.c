#include <stdio.h>
#include <stdlib.h>

void security(signed int state){
    switch(state){
        case 0:
            printf("Normal behavior\n");
            break;
        case -1:
            printf("Error behavior !! Exit...");
            exit(-1); // No need for break, it stops the process
        default:
            printf("Undefined state !!\n");
            break;
    }
    return;
}

signed int robot(void){
    static signed int i = 2;
    return (i -= 1);
}

void announce_end_of_program(void){
    printf("\nProgram is ended either with normal exit or either with error exit !!\n");
    return;
}

unsigned int main(void){

    // Takes a void fct(void) function. This function is executed at the end of the program !!
    atexit(announce_end_of_program);

    printf("Start !!\n");

    for(unsigned int i = 0; i < 10; i++){
        printf("Robot %d !!\n", i);
        security(robot());
    }

    printf("Stop....\n");

    return 0; // Or exit(0);
}
