#include <stdio.h>

#include "head.h"

char universalVariable = 0;

void addOneToStaticVariable(void){
  static char y = 1; // This variable is declared in the first utilisation
  // and at each utilisation the function remembers of the last value of the variable
  y++;
  printf("Y = %d\n", y);
  return;
}

int main(void){
  const char cantBeModified = 5;
  //cantBeModified = 4; // => It returns an error

  volatile char e = 4; // Same thing than : char e = 4;
  e = 6 + e;
  printf("E = %d\n", e);
  char o = 0;
  for(int i=0; i<11; i++){
    o = e + 1; // The value of e cansn't be added because the type volatile
    // doesn't permit to do it
  }

  printf("O = %d\n", o);

  printUniversalVariable();  
  universalVariable = 14;
  printUniversalVariable();

  auto char h = 5; // Same thing than : char h = 5;
  h = 7;

  addOneToStaticVariable();
//  printf("Y in main = %d\n", y); // => It's not correct
  addOneToStaticVariable();

  register char superVariable = 0; // This vatriable is saved in the processor
  // Warning the number of this kind of variables is very limited and it cans
  // disrupt the computer

  return 0;
}
