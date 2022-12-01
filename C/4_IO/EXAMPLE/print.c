#include <stdio.h>

void separate(void){
    printf("====================\n");
    return;
}

void mark_number_of_characters(unsigned int nbr){
    printf("%d characters written in stdout\n", nbr);
    return;
}

unsigned char main(unsigned argc, unsigned char **argv){

    printf("Salut comment ça va ?\n");
    printf("%s\n", "Yolo !!");

    separate();

    // printf() returns the number of printed characters
    unsigned int nbr = 14, nbr_of_written_characters;
    nbr_of_written_characters = printf("==> %d <==\n", nbr);
    mark_number_of_characters(nbr_of_written_characters);
    signed int nbr2 = - (signed int) nbr;
    mark_number_of_characters(printf("%d, %d\n", nbr, nbr2));

    // Tests with integers
    separate();
    nbr = 12345;
    unsigned char minimal_length = 7;

    /* '*' permits to integrate variable values in the format code */

    // Force to write spaces on the left
    printf("[%7d] vs [%d]\n", nbr, nbr); // Same 0
    printf("[%*d] vs [%d]\n", minimal_length, nbr, nbr); // Same 0

    // Force to write spaces on the right
    printf("[%-7d] vs [%d]\n", nbr, nbr); // Same 1
    printf("[%*d] vs [%d]\n", -minimal_length, nbr, nbr); // Same 1
    printf("[%-*d] vs [%d]\n", minimal_length, nbr, nbr); // Same 1
    printf("[%+-7d] vs [%d]\n", nbr, nbr); // Same 1

    // Force to write plus
    printf("[%+7d] vs [%d]\n", nbr, nbr); // Same 2
    printf("[%+*d] vs [%d]\n", minimal_length, nbr, nbr); // Same 2

    // Change the empty spaces
    separate();
    printf("{%+*d}\n", 30, 14);
    printf("{%+0*d}\n", 30, 14);
    separate();

    // Tests with floats
    float fnbr = 1234.5678; minimal_length = 20;
    unsigned char number_of_digits_after_dot = 2;
    printf("%f\n", fnbr);

    printf("[%20.2f]\n", fnbr);
    printf("[%20f]\n", fnbr);
    printf("[%.2f]\n", fnbr);
    separate();

    printf("[%20.8f]\n", fnbr);
    printf("[%-20.2f]\n", fnbr);
    printf("[%+-20.2f]\n", fnbr);
    printf("[%+-*.*f]\n", minimal_length, number_of_digits_after_dot, fnbr);

    float test = 14;
    printf("====> %#f\n", test);

    return 0;
}
