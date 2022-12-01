#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _fileName "test_file.txt"
#define size 40

void final(void){
    printf("End of the program !!\n");
    return;
}

void print_file(unsigned char *fileName);
void write_arguments(unsigned char *fileName, unsigned int argc, unsigned char **argv);

unsigned int main(unsigned int argc, unsigned char **argv){

    atexit(final);

    restart:
    printf("Starting of the program !!\n");
    printf("Clean file...\n");
    fclose(fopen(_fileName, "w"));
    printf("Done !!\n");

    unsigned char cmd[size];
    while(1){
        loop_top:
        printf("==> ");
        strncpy(cmd, "", size);
        scanf("%s", cmd);
        if(!strncmp(cmd, "restart", size)){
            goto restart;
        }
        if(!strncmp(cmd, "stop", size)){
            exit(0);
        }
        if(!strncmp(cmd, "view", size)){
            print_file(_fileName);
            goto loop_top;
        }
        if(!strncmp(cmd, "param", size)){
            write_arguments(_fileName, argc, argv);
            goto loop_top;
        }
        printf("Bad command, please write restart, stop, view or param !!\n");
    }

    return 0;
}

void print_file(unsigned char *fileName){
    static unsigned char chr;
    static unsigned long int nbr;
    static FILE *f;
    f = fopen(fileName, "r");
    fseek(f, 0, SEEK_SET);
    chr = 4;
    while(1){
        nbr = fread(&chr, sizeof(unsigned char), 1, f);
        if(nbr == 0){
            break;
        }
        printf("%c", chr);
    }
    fclose(f);
    return;
}

void write_arguments(unsigned char *fileName, unsigned int argc, unsigned char **argv){
    static unsigned int i;
    static unsigned char chr = '\n';
    static FILE *f;

    f = fopen(fileName, "a");

    fseek(f, 0, SEEK_END);
    for(i = 0; i < argc; i++){
        fwrite(*(argv + i), sizeof(unsigned char), strlen(*(argv + i)), f);
        fwrite(&chr, sizeof(unsigned char), 1, f);
    }

    fclose(f);

    return;
}
