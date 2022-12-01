#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define True 1
#define command_length 40
#define command_scan_config "%40s"

void clear_buffer(void){
    while(getchar() != 10);
    return;
}

unsigned int main(void){

    unsigned char *command = malloc(sizeof(unsigned char) * (command_length + 1));

    unsigned char **array = malloc(sizeof(unsigned char*));

    unsigned int i, array_length;

    while(True){
        printf("==> "); scanf(command_scan_config, command);
        clear_buffer();
        if(!strcmp(command, "enter")){
            printf("How many commands do you want ? "); scanf("%2d", &array_length);
            clear_buffer();

            array = realloc(array, sizeof(unsigned char*) * (array_length + 1)); // Free useless old spaces, reuser old and add new if necessary

            for(i = 0; i < array_length; i++){
                *(array + i) = malloc(sizeof(unsigned char) * (command_length + 1));
                printf("> "); scanf(command_scan_config, *(array + i));
                clear_buffer();
            }

            printf("You have entered :\n");
            for(i = 0; i < array_length - 1; i++){
                printf("%s, ", *(array + i));
            }
            printf("%s\n", *(array + i));
        }
        if(!strcmp(command, "exit")){
            break;
        }
    }

    /* ================ */
    free(command);
    free(array);

    return 0;
}
