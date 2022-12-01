#include <stdio.h>

#define length_message 60
#define print(message) printf("Line : %d\n    %-*s\n", __LINE__, length_message, message);

unsigned char main(void){

    print("Yolo !!")

    print("This line : ")
    printf("    ==> %d\n", __LINE__);

    print("Compitation day : ")
    print(__DATE__)
    print("Compilation hour : ")
    print(__TIME__)

    print("Source file name : ")
    print(__FILE__)

    if(__STDC__){
        print("According STDC, the program respects ANSI !!")
    }
    else{
        print("According STDC, the program doesn't respect ANSI !!")
    }

    return 0;
}
