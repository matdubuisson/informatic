#include <stdio.h>

struct perso{
    unsigned char name[30];
    unsigned int level;
};

void edit_perso(struct perso *this){
    printf("Perso editor !!\n");
    printf("What is the name ? ");
    scanf("%30s", (*this).name);
    printf("What is the level ? ");
    scanf("%4d", &(*this).level);
    return;
}

void edit_perso2(struct perso *this){
    printf("Perso editor 2 !!\n");
    printf("What is the name ? ");
    scanf("%30s", this->name);
    printf("What is the level ? ");
    scanf("%4d", &this->level);
    return;
}

void print_perso(struct perso *this){
    printf("Name : %s\nLevel : %d\n", (*this).name, (*this).level);
    return;
}

void print_perso2(struct perso *this){
    printf("Name : %s\nLevel : %d\n", this->name, this->level);
    return;
}

unsigned char main(void){

    struct perso joe;
    edit_perso(&joe);
    print_perso(&joe);

    struct perso joe2;
    edit_perso2(&joe2);
    print_perso2(&joe2);

    return 0;
}
