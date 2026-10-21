// Returning a pointer to the heap

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

uint16_t *secuencia(uint16_t n){
    uint16_t *arr = malloc(n * sizeof *arr);
    for(uint16_t i = 0; i < n; i++)
        arr[i] = i;
    return arr;
}

int main() {
    int n = 10;
    uint16_t *arr = secuencia(n);
    if (arr == NULL) {
        return (int) NULL;
    }
    for (int i = 0; i < n; i++) {
        printf("Address %d of arr: %p\n", i, (void*)(arr + i));
        printf("Value %d of arr: %u\n", i, arr[i]);        
    }
    
    // Requesting more memory from the heap, check its addresses
    // int *arr2 = calloc(n, sizeof(int));
    printf("\n");
    int *arr2 =malloc(n * sizeof(int));
    if (arr2 == NULL) {
        return (int) NULL;
    }
    for (int i = 0; i < n; i++) {
        printf("Address %d of arr2: %p\n", i, (void*)(arr2 + i));
        printf("Value %d of arr2: %d\n", i, arr2[i]);        
    }
    
    // Free up the memory in arr, request more, check addresses
    printf("\n");
    free(arr);
    free(arr2);
    int n2 = n + 10;
    int *arr3 = calloc(n2, sizeof(int));
    if (arr3 == NULL) {
        return (int) NULL;
    }
    for (int i = 0; i < n2; i++) {
        printf("Address %d of arr3: %p\n", i, (void*)(arr3 + i));
        printf("Value %d of arr3: %d\n", i, arr3[i]);        
    }

    
}