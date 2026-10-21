// Verlorene Speicherallozierung

#include <stdio.h>
#include <stdlib.h>

int *ints;

int main(void){

  ints = malloc(12);
  ints += 1;


}
