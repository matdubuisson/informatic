#include <stdio.h>
#include <stdlib.h>

#define interline() printf("\n#############################################\n");

int main(void){

/*

X sera les petits tableaux et Y sera les tableau contenant les addresses
des petits tableaux.

tableau X0 => [ datas ]
tableau x1 => [ datas ]
tableau X2 => [ datas ]
tableau X3 => [ datas ]
tableau X4 => [ datas ]

mega_tableay Y => [ &X0, &X1, &X2, &X3, &X4 ];

*/

  int x, y; // Y maximum 6
  printf("X = "); scanf("%d", &x); printf("\n");
  printf("Y = "); scanf("%d", &y); printf("\n");

  // Allocation mémoire pour le méga tableau contenir des addresses
  int **mega_frame = 0;
  mega_frame = malloc(sizeof(int) * (y + 1));

  int e, a;
  for(e = 0; e < y; e++){
    int *frame = malloc(sizeof(int) * (x + 1));
    mega_frame[e] = frame;
  }

  // Donne des valeurs
  for(e = 0; e < y; e++){
    for(a = 0; a < x; a++){
      mega_frame[e][a] = a + e;
    }
  }

  // Bête affichage du mega tableau
  for(e = 0; e < y; e++){
    for(a = 0; a < x; a++){
      printf("[ %d ]", mega_frame[e][a]);
    }
    printf("\n");
  }

  // Libération de la mémoire de chaque petit tableau puis du mega tableau
  free(mega_frame);

  return 0;
}
