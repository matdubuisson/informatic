#include <stdio.h>
#include <stdlib.h>

#define size_frame 8
#define size_mega_frame 6

#define interline() printf("\n====================================\n");

int main(void){

  /* =============================== */

  int var0 = 14;
  int *var1 = &var0;
  printf("VAR0 = %d; VAR1 = %d;\n", var0, *var1);
  var0 = 16;
  printf("VAR0 = %d; VAR1 = %d;\n", var0, *var1);
  *var1 = 15;
  printf("VAR0 = %d; VAR1 = %d;\n", var0, *var1);

  interline();
  /* =============================== */

  int frame[size_frame] = { 1, 2, 3, 4, 5, 6, 7 /*, 0*/ };
  int u;
  for(u = 0; u < size_frame - 1; u++){
    printf("FRAME[%d] = %d\n", u, frame[u]);
  }
  int *pointerOnFrame = frame;
  for(u = 0; u < size_frame - 1; u++){
    printf("POINTER_ON_FRAME[%d] = %d\n", u, pointerOnFrame[u]);
    pointerOnFrame[u] = -4;
  }
  for(u = 0; u < size_frame - 1; u++){
    printf("FRAME[%d] = %d\n", u, frame[u]);
  }

  interline();
  /* =============================== */

  int frame0[size_frame] = { 1, 2, 3, 4, 5, 6, 101 /*, 0*/ };
  int frame1[size_frame] = { 1, 2, 3, 4, 5, 6, 102 /*, 0*/ };
  int frame2[size_frame] = { 1, 2, 3, 4, 5, 6, 103 /*, 0*/ };
  int frame3[size_frame] = { 1, 2, 3, 4, 5, 6, 104 /*, 0*/ };
  int frame4[size_frame] = { 1, 2, 3, 4, 5, 6, 105 /*, 0*/ };

  int *mega_frame[size_mega_frame];

  mega_frame[0] = frame0;
  mega_frame[1] = frame1;
  mega_frame[2] = frame2;
  mega_frame[3] = frame3;
  mega_frame[4] = frame4;

  int e;
  for(e = 0; e < size_mega_frame - 1; e++){
    for(u = 0; u < size_frame - 1; u++){
      printf("MEGA_FRAME[%d][%d] = %d\n", e, u, mega_frame[e][u]);
    }
  }

  interline();

  printf("SIZE OF INTEGER = %ld\n", sizeof(int));
  printf("SIZE OF FRAME = %ld\n", sizeof(frame));
  printf("SIZE OF MEGA_FRAME = %ld\n", sizeof(mega_frame));

  /* =============================== */

  return 0;
}
