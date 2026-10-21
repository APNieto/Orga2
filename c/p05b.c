// Forced errors to be checked with valgrind

#include <stdio.h>
#include <stdlib.h>

typedef struct defo{
    char ch;
    short sh;
    int enter;
    long longo;
} defo;


int main() {
    
    printf("sizeof(defo) = %zu\n", sizeof(defo));
    
    defo *pdefo = malloc(sizeof(defo));

}