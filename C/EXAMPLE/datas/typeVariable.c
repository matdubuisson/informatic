#include <stdio.h>

int main(void){

  printf("Type of data       | bytes in memory\n");

  printf("_____________________________\n");

  printf("char               | %ld\n", sizeof(char));
  printf("signed char        | %ld\n", sizeof(signed char));
  printf("unsigned char      | %ld\n", sizeof(unsigned char));

  printf("_____________________________\n");

  printf("int                | %ld\n", sizeof(int));
  printf("signed int         | %ld\n", sizeof(signed int));
  printf("unsigned int       | %ld\n", sizeof(unsigned int));

  printf("_____________________________\n");

  printf("short              | %ld\n", sizeof(short));
  printf("signed short       | %ld\n", sizeof(signed short));
  printf("unsigned short     | %ld\n", sizeof(unsigned short));

  printf("_____________________________\n");

  printf("short int          | %ld\n", sizeof(short int));
  printf("signed short int   | %ld\n", sizeof(signed short int));
  printf("unsigned short int | %ld\n", sizeof(unsigned short int));

  printf("_____________________________\n");

  printf("long               | %ld\n", sizeof(long));
  printf("signed long        | %ld\n", sizeof(signed long));
  printf("unsigned long      | %ld\n", sizeof(unsigned long));

  printf("_____________________________\n");

  printf("long int           | %ld\n", sizeof(long int));
  printf("signed long int    | %ld\n", sizeof(signed long int));
  printf("unsigned long int  | %ld\n", sizeof(unsigned long int));

  printf("_____________________________\n");

  printf("float              | %ld\n", sizeof(float));

  printf("_____________________________\n");

  printf("double             | %ld\n", sizeof(float));

  return 0;
}
