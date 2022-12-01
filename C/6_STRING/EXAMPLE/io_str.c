#include <stdio.h>
#include <string.h>

#define size 40

unsigned int main(void){

    unsigned char name[size];
    strcpy(name, "Racteur");

    // There are getchar() and putchar(), see IO chapter

    // Output :
    puts(name);
    fputs(name, stdout);
    fputc(10, stdout); // Same function than putc()

    // Input :
    unsigned int chr = fgetc(stdin); // Same function than getc()
    while(getchar() != 10); // Clear buffer
    printf("==> %c, %d\n", chr, chr);
    // gets(name); // This function has been removed since C11
    fgets(name, size, stdin);
    printf("Name => %s\n", name);

    return 0;
}
