#include <stdio.h>

void print_int_array(unsigned int *int_array){

    unsigned int c = 1, i = 0;
    while(c != '\0'){
        c = int_array[i];
        printf("%d, ", c);
        i++;
    }
    printf("\n");

    return;
}

unsigned char main(unsigned char argc, unsigned char **argv){

    // Real contain => [1, 2, 3, \0] # \0 markes the end of the array
    unsigned int int_array0[] = {1, 2, 3}; // Takes more memory
    unsigned int int_array1[4] = {1, 2, 3};
    unsigned int int_array2[4];
    unsigned char i;
    for(i = 0; i < 3; i++){
        int_array2[i] = i + 1;
    }
    printf("Overflow of int_array2 :\n");
    print_int_array(int_array2); // Overflow !!
    int_array2[i] = '\0'; // Not a good idea for integer array because '\0' is an equivalent of 0 and zero could be used as integer number
    // The best thing to print an integer array is to know before the length of the list and to memory it

    // It is rejected :
    //unsigned int *int_array3 = {1, 2, 3};
    unsigned int int_array4[] = {1, 2, 3, '\0'};
    unsigned int int_array5[4] = {1, 2, 3, '\0'};

    print_int_array(int_array0);
    print_int_array(int_array1);
    print_int_array(int_array2);
    print_int_array(int_array4);
    print_int_array(int_array5);

    unsigned char myName0[] = "Racteur";
    unsigned char myName1[7+1] = "Racteur";
    unsigned char myName2[] = {'R', 'a', 'c', 't', 'e', 'u', 'r'}; // This type of declaration makes problems, it takes more memory
    unsigned char myName3[7+1] = {'R', 'a', 'c', 't', 'e', 'u', 'r'};
    unsigned char myName4[] = {'R', 'a', 'c', 't', 'e', 'u', 'r', '\0'};
    unsigned char myName5[7+1] = {'R', 'a', 'c', 't', 'e', 'u', 'r', '\0'};

    printf("%s\n", myName0);
    printf("%s\n", myName1);
    printf("%s\n", myName2);
    printf("%s\n", myName3);
    printf("%s\n", myName4);
    printf("%s\n", myName5);

    return 0;
}
