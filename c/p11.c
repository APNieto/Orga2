// Verlorene Speicherallozierung

#include <stdio.h>
#include <stdlib.h>

int main(void){

  int (*arr)[90] = malloc(sizeof(int) * 90);

  arr = NULL;
  free(arr);



}
