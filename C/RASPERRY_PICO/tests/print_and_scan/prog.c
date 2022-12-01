#include <stdio.h>        
            
#include "pico/stdlib.h"  
#include "hardware/uart.h"
            
#define size 40           
            
unsigned char *get_line(unsigned char *string){     
    static unsigned char chr;                       
    static unsigned int i;
    i = 0;  
    while(((chr = getchar()) != 13) && (i < size - 1)){
        *(string + i) = chr;                        
        i++;
    }       
    while(i < size - 1){  
        *(string + i) = 0;
        i++;
    }       
    return string;        
}           
            
unsigned int main(void){  
            
    unsigned int i;       
    unsigned char name[size], chr;                  
            
    stdio_init_all();     
            
    start:  
    printf("What is your name ?");                  
    get_line(name);       
    for(i = 0; i < 10; i++){
        printf("%s : %d\n", name, i);               
        sleep_ms(500);    
    }       
    goto start;           
            
    return 0;
}  
