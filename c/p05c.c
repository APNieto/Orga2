// Forced errors to be checked with valgrind

#include <stdio.h>
#include <stdlib.h>

typedef struct defo{
    char ch;
    short sh;
    int enter;
    long *p_longo;
} defo;


int main() {
    
    printf("sizeof(defo) = %zu\n", sizeof(defo));
    
    defo *pdefo = malloc(sizeof(defo));
    pdefo->ch = 'a';
    pdefo->p_longo = malloc(sizeof(long));

    free(pdefo);

}