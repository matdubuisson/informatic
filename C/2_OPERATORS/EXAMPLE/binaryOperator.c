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

void __printBinaryIntegerNumber(signed int nbr, unsigned char nbrOfBytes){
  if(nbrOfBytes > 8){
    nbrOfBytes = 8;
  }
  unsigned char bits[65];
  int NEGATIVE = 0;
  if(nbr < 0){
    nbr *= -1;
    NEGATIVE = 1;
  }
  signed int cp;
  signed int e = 0;
  for(e = 0; e < 8; e++){
    bits[e] = OFF;
  }
  while(nbr >= 0){
    e = 0;
    do{
      cp = nbr;
      cp -= exposant(2, e);
      e++;
    }while(cp >= 0);
    e -= 2;
    nbr -= exposant(2, e);
    bits[(8 * nbrOfBytes) - 1 - e] = ON;
  }
  if(NEGATIVE){
    for(e = 0; e < 8 * nbrOfBytes; e++){
      if(bits[e] == ON){
        bits[e] = OFF;
      }
      else{
        bits[e] = ON;
      }
    }
  }
  for(e = 0; e < 8 * nbrOfBytes; e++){
    printf("%c", bits[e]);
  }
  return;
}

int main(void){
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
