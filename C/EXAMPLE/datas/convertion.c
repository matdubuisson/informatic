#include <stdio.h>
#include <limits.h>

int main(void){
  unsigned char e = 0;
  while(e < UCHAR_MAX){
    e++;
  }

  printf("The data cans not pass the limit of the maximal size [ %d ]...\n", e);
  printf("Do you want to convert the [ unsigned char ] data in [ unsigned int ] ?\n");

  printf("Yes or No. Y/N ");
  char response;
  scanf("%c", &response);
  printf("\n");

  while((response != 'Y') && (response = 'N')){
    printf("Please put a valid character to response : ");
    scanf("%c", &response);
    printf("\n");
  }

  if(response == 'Y'){
    e = (unsigned int) INT_MAX;
    printf("[ %d ]\n", e);
  }

  printf("END of the program !!\n");

  return 0;
}
