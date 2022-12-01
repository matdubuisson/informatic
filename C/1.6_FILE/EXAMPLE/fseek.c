#include <stdio.h>

#define fileName "test_fseek.txt"

unsigned int main(void){

    FILE *f;
    unsigned char chr;

    unsigned char *message = "abc\ndef\nghi\n";
    fputs(message, f = fopen(fileName, "w"));
    fclose(f);

    // ftell() versus index it's : index = ftell() - 1

    f = fopen(fileName, "r");

    fseek(f, 0, SEEK_SET); // Go to begin;

    fread(&chr, sizeof(unsigned char), 1, f);
    printf("First character : %c\n", chr);
    printf("Position : %ld\n", ftell(f));

    fread(&chr, sizeof(unsigned char), 1, f);
    printf("Second character : %c\n", chr);
    printf("Position : %ld\n", ftell(f));

    fseek(f, 0, SEEK_SET);
    fread(&chr, sizeof(unsigned char), 1, f);
    printf("First character : %c\n", chr);
    printf("Position : %ld\n", ftell(f));

    fseek(f, 2, SEEK_SET);
    fread(&chr, sizeof(unsigned char), 1, f);
    printf("Third character : %c\n", chr);
    printf("Position : %ld\n", ftell(f));

    fseek(f, -2, SEEK_END);
    fread(&chr, sizeof(unsigned char), 1, f);
    printf("Before last character : %c\n", chr);
    printf("Position : %ld\n", ftell(f));

    fseek(f, -1, SEEK_END); // Go to end;
    fread(&chr, sizeof(unsigned char), 1, f);
    printf("Last character : [%c]\n", chr);
    printf("Position : %ld\n", ftell(f));

    fseek(f, 0, SEEK_SET); // Go to begin;
    fread(&chr, sizeof(unsigned char), 1, f);
    printf("First character : %c\n", chr);
    printf("Position : %ld\n", ftell(f));

    // fseek(f, 0, SEEK_END); ==> It's the limit, no character at this position !!

    fclose(f);

    return 0;
}
