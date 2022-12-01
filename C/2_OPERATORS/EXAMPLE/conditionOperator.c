#include <stdio.h>

int main(void){

  int Boolean = (5 > 4); // = TRUE = 1
  int Boolean2 = (5 != 5); // = FALSE = 0
  printf("Boolean = %d; Boolean2 = %d\n", Boolean, Boolean2);

  int a = 4 == 4 * 5 > -4; // Same thing than : 4 == ( (4 * 5) > -4 )
  int b = 5 > 4 > 3; // Same thing than : (5 > 4) > 3;
  int c = 6 > 4 != 6 <= 10; // Same thing than : (6 > 4) != (6 <= 10);
  printf("a = %d; b = %d; c = %d\n", a, b, c);

  return 0;
}
