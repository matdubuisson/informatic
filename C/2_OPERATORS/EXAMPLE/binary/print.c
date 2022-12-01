#include <stdio.h>

#define OFF 48
#define ON 49

int exposant(int base, int exp){
  int res = 1;
  for(int e = 0; e < exp; e++){
    res *= base;
  }
  return res;
}

unsigned char bits[80];

void __printBinaryNumber(signed long long int nbr, unsigned char nbrOfBytes){

  signed short e;
  for(e = 0; e < 80; e++){
    bits[e] = 0;
  }

  unsigned char NEGATIVE = 0;
  if(nbr < 0){
    NEGATIVE = 1;
    nbr *= -1;
  }

  signed long long int cp = nbr, deleter = 1;
  unsigned short exposant = 0;
  while(nbr > 0){
    cp = nbr;
    deleter = 1;
    exposant = 0;
    while(cp >= deleter){
      deleter *= 2;
      exposant++;
    }
    deleter /= 2;
    exposant--;
    bits[exposant] = 1;
    nbr -= deleter;
  }

  if(NEGATIVE){
    for(e = 0; e < 80; e++){
      if(bits[e]){
        bits[e] = 0;
      }
      else{
        bits[e] = 1;
      }
    }
  }

  for(e = 8 * nbrOfBytes - 1; e >= 0; e--){
    printf("%d", bits[e]);
  }

  return;
}
/*
int main(void){
  __printBinaryIntegerNumber(400038, 4);
  printf("\n");
  unsigned int a = 37, b = 71;
  printf("a = %d; b = %d\n", a, b);
  printf("a = ");
  __printBinaryIntegerNumber(a, 1);
  printf("\nb = ");
  __printBinaryIntegerNumber(b, 1);
  printf("\na & b = ");
  __printBinaryIntegerNumber(a & b, 1);
  printf("\na | b = ");
  __printBinaryIntegerNumber(a | b, 1);
  printf("\na ^ b = ");
  __printBinaryIntegerNumber(a ^ b, 1);
  printf("\n~ a = ");
  __printBinaryIntegerNumber(~ a, 1);
  printf("\na << 2 = ");
  __printBinaryIntegerNumber(a << 2, 1);
  printf("\na >> 2 = ");
  __printBinaryIntegerNumber(a >> 2, 1);
  printf("\n");

  __printBinaryIntegerNumber(38, 1);
  printf("\n");
  __printBinaryIntegerNumber(-37, 1);
  printf("\n[ %d ]\n", ~ a);

  return 0;
}
*/
