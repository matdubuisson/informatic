#include <stdio.h>

unsigned char main(unsigned char argc, unsigned char **argv){

    // While loop :
    unsigned int value = 0;
    while(value != 14){
    	printf("Write 14 :");
	scanf("%d", &value);
    }

    // Until loop :
    do{ // With a simple while loop, this new loop shouldn't be executed !!
    	printf("Re-write 14 :");
	scanf("%d", &value);
    }while(value != 14);

    // Count loop :
    for(unsigned char i = 0; i < value; i++){
    	printf("%d**2 = %d\n", i, i*i);
    }

    return 0;
}
