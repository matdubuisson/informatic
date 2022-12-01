#include <stdio.h>

#define size 50

unsigned int main(void){

    unsigned char line[size];
    unsigned int i;

    puts("======================");

    FILE *f = fopen("test_fscanf.txt", "r");

    for(i = 0; i < 6; i++){
        fscanf(f, "%s", line);
        printf("%s\n", line);
    }

    fclose(f);

    puts("======================");

    f = fopen("test_fscanf.txt", "r");
   
    printf("fgets() takes the asked size except it reads a '\n'"); 
    for(i = 0; i < 14; i++){
        printf("String with %d characters : ", i);
        fgets(line, i, f);
        printf("[%s]\n", line);
    }
    
    fclose(f); 

    puts("======================");              
     
    f = fopen("test_fscanf.txt", "r");

    printf("Print the file :\n");
    unsigned char chr = 0;
    goto here;
    do{
        printf("%c", chr);
        here:
        chr = fgetc(f);
    }while(!feof(f));

    fclose(f);

    return 0;
}
