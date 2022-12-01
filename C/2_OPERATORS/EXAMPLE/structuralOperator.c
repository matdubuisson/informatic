#include <stdio.h>

struct lotOfDatas{
  unsigned char ue;
  signed char e;
};

void printStructure(void *myStruct){
  struct lotOfDatas *pointer = myStruct;
  printf("E = %d; UE = %d\n", pointer->e, pointer->ue);
  // Use the "->" as it's a pointer on the structure
}

int main(void){
  struct lotOfDatas ld;
  ld.e = -128; // Use the "." as it's point directly on the structure
  ld.ue = 255;

  printStructure(&ld);

  return 0;
}
