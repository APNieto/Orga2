
#include <stdio.h>
#include <stdlib.h>

int main(void){

  int **arr = malloc(sizeof(int) * 10);

  printf("Pointer auf ganzer Heap-Speicherblock:\n");
  printf("(arr) == %p\n", (arr));
  printf("(arr + 1) == %p\n", (arr + 1));
  
  printf("Erstem Pointer in Heap-Speicherblock:\n");
  printf("(*arr) == %p\n", (*arr));
  printf("(*arr + 1) == %p\n", (*arr + 1));
  
  printf("Adresse des erstem pointed int:\n");
  printf("&(**arr) == %p\n", &(**arr));
  printf("&(**arr + 1) == %p\n", &(**arr) + 1);


}
