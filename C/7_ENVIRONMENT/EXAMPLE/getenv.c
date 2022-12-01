#include <stdio.h>
#include <stdlib.h>

unsigned int main(void){

    printf("At line %d starts :\n", __LINE__);
    printf("PATH : %s\n", getenv("PATH"));
    printf("HOME : %s\n", getenv("HOME"));
    printf("ROOT : %s\n", getenv("ROOT"));

    return 0;
}
