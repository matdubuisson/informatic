#include <stdio.h>

unsigned char main(unsigned argc, unsigned char **argv){

    unsigned int value = 0;
    while(1){ // Infinite loop
        printf("Write 14 : ");
	scanf("%d", &value);
        if(value != 14){
	    printf("Bad value !!\n");
	    continue;
	}
	printf("Good answer !!\n");
	break;
    }

    return 0;
}
