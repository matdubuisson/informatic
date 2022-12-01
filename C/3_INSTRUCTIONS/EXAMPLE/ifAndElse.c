#include <stdio.h>

int main(void){

  printf("What is your favorite character ? \n");
  char c = 4;
  if((c = getchar()) == 48) printf("You have written zero !!\n");
  else if(c == 49) printf("You have written one !!\n");
  else printf("You have written something else...\n");

  if((c = getchar()) == '\n'){
    printf("The second character is the changer of line !!\n");
  }
  else if(1){
    // Never executed. This else depends of the last if()
    // Normally it executes the next if()
  }
  else{
    // Never executed. This else depends on the last if()
    // so the if() from the last else if()
  }

  printf("What is your favorite number ?\n");
  unsigned int nbr;
  scanf("%d", &nbr);

  if(nbr >= 100){
    printf("Your number has three characters !!\n");
  }
  else if(nbr < 10){
    printf("Your number has only one character !!\n");
  }
  else{
    printf("Your number has two characters !!\n");
  }

  return 0;
}
