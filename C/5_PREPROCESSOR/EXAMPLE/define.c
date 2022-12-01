#include <stdio.h>

#define myName "Racteur"
#define myNbr 14
#define PI 3.14
#define salut printf("Salut !!\n"); // With ';'
#define bonjour printf("Bonjour !!\n")
#define length 30

// Make python
#define False 0
#define True 1
#define not !
#define is ==

#define boolean unsigned char
#define _int unsigned int

boolean include(_int *lst, _int target){
    for(_int i = 0; i < length; i++){
        if(lst[i] is target){
            return True;
        }
    }
    return False;
}

#define in(lst, target) include(lst, target)

#define plus(a, b) a + b
#define minus(a, b) a - b
#define print(x) printf("The variable " #x " is %d !!\n", x)

unsigned int _exponant(unsigned int base, unsigned int exponent){
    if(!base){
        return 0;
    }
    unsigned int result = 1;
    while(exponent > 0){
        result *= base;
        exponent -= 1;
    }
    return result;
}

// exp exists in math.h included in stdlib.h ; So it's an alternative to name my callings
// of _exp() as exp()
#define exp(a, b) _exponant(a, b)

unsigned char main(void){

    // unsigned int length = 30; unsigned int lst[length]; // ==> Rejected in compilation;
    unsigned int lst[length];
    for(_int i = 0; i < length; i++){
        lst[i] = i;
    }

    printf("%s\n%d\n%f\n", myName, myNbr, PI);
    salut bonjour;
    salut
    bonjour;

    if(in(lst, 4)){
        printf("4 is in lst !!\n");
    }
    if(not in(lst, 200)){
        printf("200 isn't in lst !!\n");
    }

    print(plus(4, 6));
    print(minus(6, 4));

    print(exp(5, 4));

    return 0;
}
