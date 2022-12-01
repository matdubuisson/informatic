#include <stdio.h>
#include <stdlib.h> // Where is malloc() and free()
#include <string.h>

#define empty_character 33

#define word_type unsigned char
#define word_length 30
#define word_list_length 5

word_type *create_word(void){
    static unsigned int i; // Declared only once !!
    word_type *word;
    word = malloc(sizeof(word_type) * (word_length + 1)); // More one for last character that is \0
    for(i = 0; i < word_length; i++){
        *(word + i) = empty_character;
    }
    *(word + i) = 0; // Last character, so the limit
    return word;
}

word_type **create_word_list(void){
    static unsigned int i;
    word_type **word_list;
    word_list = malloc(sizeof(word_type*) * (word_list_length + 1));
    for(i = 0; i < word_list_length; i++){
        *(word_list + i) = create_word();
    }
    *(word_list + i) = 0;
    return word_list;
}

void print_word_list(word_type **word_list){
    static unsigned int i;
    printf("Begin of list :\n");
    for(i = 0; i < word_list_length; i++){
        printf("%d) %s\n", i, *(word_list + i));
    }
    printf("End of list !!\n");
    return;
}

unsigned char main(void){

    printf("Length of unsigned char : %d\nLength of (unsigned char)* : %d\n", (unsigned int) sizeof(unsigned char), (unsigned char) sizeof(unsigned char *));

    word_type *myName = create_word();
    printf("==> %s\n", myName);
    strcpy(myName, "Racteur");
    printf("==> %s\n", myName);
    free(myName);

    word_type **names = create_word_list();
    print_word_list(names);
    strcpy(*(names + 0), "Racteur");
    strcpy(*(names + 1), "Joe");
    strcpy(*(names + 2), "Ralph");
    strcpy(*(names + 3), "Philou");
    strcpy(*(names + 4), "Zircoulouc");
    print_word_list(names);
    free(names);

    return 0;
}
