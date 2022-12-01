#include <stdio.h>
#include <stdlib.h>

unsigned int main(void){

    system("pwd");
    signed int command_return = system("ls -l");
    command_return = system("echo test");

    return 0;
}
