#include <stdio.h>

int main(void){
  unsigned char str[100], str2[100];
  printf("Write here : ");
  scanf("%s", str);
  printf("\nYour wrote : %s\nWrite again : ", str);
  scanf("%s", str);
  printf("\nYou wrote again : %s\n", str2);
  return 0;
}
