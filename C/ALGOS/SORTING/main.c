#include <stdio.h>
#include <stdlib.h>

#define size 10

unsigned char lstnequal(const unsigned int *lst0, const unsigned int *lst1, unsigned int length){
    static unsigned int i;
    for(i = 0; i < length; i++){
        if(*(lst0 + i) != *(lst1 + i)){
            return 0;
        }
    }
    return 1;
}

unsigned int *lstnclear(unsigned int *lst, unsigned int length){
    static unsigned int i;
    for(i = 0; i < length; i++){
        *(lst + i) = 0;
    }
    return lst;
}

unsigned int *lstncopy(unsigned int *lst0, const unsigned int *lst1, unsigned int length){
    static unsigned int i;
    for(i = 0; i < length; i++){
        *(lst0 + i) = *(lst1 + i);
    }
    return lst0;
}

unsigned int lstnprint(const unsigned int *lst, unsigned int length){
    static unsigned int i, cnt;
    for(i = 0, cnt = 1; i < length; i++, cnt += 6){
        printf("[%3d] ", *(lst + i));
    }
    printf("\n");
    return cnt;
}

unsigned int main(void){

    unsigned int lst0[size];
    // printf("==> %ld\n", sizeof(lst0)); // ==> 160

    unsigned int lst1[] = {1, 4, 7, 2, 4, 0, 1, 5, 1, 0};
    unsigned int lst2[] = {0, 0, 1, 1, 1, 2, 4, 4, 5, 7};

    lstnprint(lst0, size);
    lstnclear(lst0, size);
    lstnprint(lst0, size);
    lstncopy(lst0, lst1, size);
    lstnprint(lst0, size);

    if(lstnequal(lst0, lst1, size)){
        printf("lst0 equals lst1\n");
    }
    else{
        printf("lst0 doesn't equal lst1\n");
    }

    if(lstnequal(lst0, lst2, size)){
        printf("lst0 equals lst2\n");
    }
    else{
        printf("lst0 doesn't equal lst2\n");
    }

    return 0;
}
