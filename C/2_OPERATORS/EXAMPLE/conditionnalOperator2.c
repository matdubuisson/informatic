#include <stdio.h>

int main(void){
  printf("Do you like the appel ? Yes=y and no=n...\n");
  signed char choice;
  scanf("%1c", &choice);

  //signed char continue;

  //IF :
  choice == 'y' ? printf("You like the appel !!\n") :
  // ELSE IF :
  choice == 'n' ? printf("You don't like the appel...\n") :
  // ELSE :
  printf("Sorry but it isn't a available response...\n");

  return 0;
}
