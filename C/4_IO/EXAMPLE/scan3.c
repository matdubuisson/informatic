#include <stdio.h>

#define size 30

void clear_buffer(void){
    while(getchar() != 10);
    return;
}

void clear_string(unsigned char *string){
    for(unsigned char i = 0; i < size; i++){
        *(string + i) = 0;
    }
    return;
}

unsigned char main(void){

    unsigned char i;
    unsigned char phone_number[size];

    // Force to include only some characters
    printf("Write your phonenumber : ");
    for(i = 0; i < 2; i++){
        scanf("%[0123456789]", phone_number);
        printf("==> %s\n", phone_number);
        // clear_buffer() avoids problem
        // clear_string() avoids perpetual auto scanf. Try to uncomment it
        clear_buffer(); clear_string(phone_number);
    }


    // Don't scan while you don't see a character NOT IN the list
    printf("Write your phonenumber (part2) : ");
    for(i = 0; i < 2; i++){
        scanf("%*[0123456789]%s", phone_number);
        printf("==> %s\n", phone_number);
        // clear_buffer() avoids problem
        // clear_string() avoids perpetual auto scanf. Try to uncomment it
        clear_buffer(); clear_string(phone_number);
    }

    // Don't scan while you don't see a character IN the list
    printf("Write your phonenumber (part3) : ");
    for(i = 0; i < 2; i++){
        scanf("%*[^0123456789]%s", phone_number);
        printf("==> %s\n", phone_number);
        // clear_buffer() avoids problem
        // clear_string() avoids perpetual auto scanf. Try to uncomment it
        clear_buffer(); clear_string(phone_number);
    }

    // Get the number of scaned characters
    unsigned number_of_scaned_characters = 0;
    printf("======================\n");
    for(i = 0; i < 2; i++){
        scanf("%[0123456789]%n", phone_number, &number_of_scaned_characters);
        printf("%d scaned characters ==> %s\n", number_of_scaned_characters, phone_number);
        clear_buffer(); clear_string(phone_number);
    }

    // Limit the scan
    printf("======================\n"); 
    for(i = 0; i < 2; i++){
        scanf("%4[0123456789]%n", phone_number, &number_of_scaned_characters);
        printf("%d scaned characters ==> %s\n", number_of_scaned_characters, phone_number);
        clear_buffer(); clear_string(phone_number);
    }

    // Limit the scan
    unsigned char first_character;
    printf("======================\n");
    for(i = 0; i < 2; i++){
        scanf("%*[0123456789]%c", &first_character);
        printf("==> %c\n", first_character);
        clear_buffer(); clear_string(phone_number);
    }

    return 0;
}
