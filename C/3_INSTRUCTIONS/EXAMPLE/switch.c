#include <stdio.h>

unsigned char main(unsigned char argc, unsigned char **argv){

    unsigned int value;
    printf("Choose your value : ");
    scanf("%d", &value);

    switch(value){
        case 0:
	    printf("It is 0 !!\n");
	    break;
	case 1:
	    printf("It is 1 !! Warning, without break it executes the next case (or default)\n");
	case 2:
	    printf("It is 2 !!\n");
	    break;
	case -4000:
	    printf("Not possible !!\n");
	    break;
	default:
	    printf("Either it's 1 or it isn't in [0, 1, 2] !!\n");
	    break;
    }

    return 0;
}
