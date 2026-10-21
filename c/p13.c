// Verlorene Speicherallozierung

#include <stdio.h>
#include <stdlib.h>

int **pop;

int main(void){

  // int **arr = malloc(sizeof(int*) * 11);
  // arr[1] = malloc(sizeof(int) * 3);
  // free(arr);


  pop = malloc(sizeof(int*) * 10);
  for (int i = 0; i < 10; i++) {
    pop[i] = malloc(sizeof(int));
    *pop[i] = i * 10;
    free(pop[i]);
  }

  free(pop);


}
