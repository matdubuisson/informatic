#include <stdio.h>
#include <stdlib.h>

#define size 10

unsigned int main(void){

    unsigned int **matrix;
    matrix = malloc(sizeof(unsigned int*) * size);

    unsigned int test_list[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    printf("%d, %d\n", *(test_list), *(test_list + 1));

    unsigned int i, j;
    for(i = 0; i < size; i++){
        *(matrix + i) = test_list;//malloc(sizeof(unsigned int*
    }

    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            printf("m[%d][%d] = %d; ", i, j, *(*(matrix + i) + j));
        }
        printf("\n");
    }

    free(matrix);

    return 0;
}
