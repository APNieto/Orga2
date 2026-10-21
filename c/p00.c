// Debugging

#include <stdio.h>

void contarHasta(int hasta){
    for(int i = 0; i < hasta; i++){
    printf("%d\n", i);
    }

}

int main(void){
  contarHasta(10);
  
  long arr[5];
  arr[5] = 34;
  long l = arr[0] + 1;
  arr[1] = l;

  printf("ended");
}
