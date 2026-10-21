// Double pointers

#include <stdio.h>
#include <stdlib.h>

void fun(int **pp){
    printf("fun() called. local pp = &p1. printing **(++pp): %d\n", **(++pp));
}



int main()
{
    int *p1 = malloc(sizeof(int));
    int *p2 = malloc(sizeof(int));
    *p1 = 10;
    *p2 = 20;
    
    printf("*p1 prior to fun(): %d\n", *p1);
    fun(&p1);

    return 0;
}