#include <stdio.h>

unsigned int main(void){

    float fn = 15.7;
    signed int in = -1086;
    unsigned char *name = "Racteur";

    FILE *f = fopen("test_fprintf.txt", "w");

    fprintf(f, "fn = %f; in = [%*d]\nname = %s\n", fn, 40, in, name);

    fputs(name, f);
    fputc('\n', f);
    fputc('!', f);
    fputc('\n', f);

    fclose(f);

    return 0;
}
