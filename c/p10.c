// heap-fehler erzwingen

#include <stdio.h>
#include <stdlib.h>

int main(void){

  int (*arr)[10] = malloc(sizeof(int) * 10);
  (*arr)[11] = 12;  // Write error
  printf("(*arr)[12] == %d\n", (*arr)[12]);  // Read error

  char *ch = malloc(1);
  if (*ch > 97)
    printf("Ins if Block.\n");

  // Versuch, einen segfault zu erzwingen
  (*arr)[99999 * 999] = 10;

}
