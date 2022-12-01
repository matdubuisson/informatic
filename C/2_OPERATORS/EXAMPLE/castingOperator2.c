#include <stdio.h>

#include "binary/__binary.h"

//__printBinaryNumber

int main(void){
  unsigned char a;

  signed char v0 = -14;
  unsigned short v1 = 4000;
  signed short v2 = -2000;

  /* Conversion from a negative number to a positive :
  In fact, the binary number is conserved with a small
  modification. The negative number becomes positive and
  adds to its value one. So :
  readAsNegative(binNbr) => readAsPositive(binNbr + 1)
  */
  a = (unsigned char) v0;
  printf("v0 = %d; sizeof(v0) = %ld\n", v0, sizeof(v0));
  printf("v0 = "); __printBinaryNumber(v0, sizeof(v0));
  printf("\n");
  printf("a = %d; sizeof(a) = %ld\n", a, sizeof(a));
  printf("a = "); __printBinaryNumber(a, sizeof(a));
  printf(" (= v0 + 00000001)\n");

  /* Conversion from a grander positive number to a smaller positive :
  For this case, the smaller gets the eight first bits of the grander.
  The type short has sixteen bits whereas the char has eight. The type
  char gets only the eight first bits of the type short.
  */
  printf("\n=================\n");
  a = (unsigned char) v1;
  printf("v1 = %d; sizeof(v1) = %ld\n", v1, sizeof(v1));
  printf("v1 = "); __printBinaryNumber(v1, sizeof(v1));
  printf("\n");
  printf("a = %d; sizeof(a) = %ld\n", a, sizeof(a));
  printf("a = "); __printBinaryNumber(a, sizeof(a));
  printf("\n");

  /* Conversion form a grander negative number to a smaller positive number :
  Here it uses the two viewed under cases therefore it's the two situations.
  The type char cans take only the first eight bits as it's smaler and it adds
  one its value because it's a converstion negative to positive.
  */
  printf("\n=================\n");
  a = (unsigned char) v2;
  printf("v2 = %d; sizeof(v2) = %ld\n", v2, sizeof(v2));
  printf("v2 = "); __printBinaryNumber(v2, sizeof(v2));
  printf("\n");
  printf("a = %d; sizeof(a) = %ld\n", a, sizeof(a));
  printf("a = "); __printBinaryNumber(a, sizeof(a));
  printf("\n");

  return 0;
}
