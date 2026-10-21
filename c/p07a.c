// Funtion pointers

#include <stdio.h>

// void print_int(int x) {
//     printf("%d\n", x);
// }

void pretty_print_int(int x) {
    printf("Entero[%lu bits]: %d\n", sizeof(x)*8, x);
}

int main()
{

    void (*pr) (int) = pretty_print_int;
    pr(12);

    pretty_print_int(13);
    
    // pr = print_int;
    // pr(14);
    
    printf("&pretty_print_int == %p\n", &pretty_print_int);
    printf("pretty_print_int == %p\n", pretty_print_int);
    printf("pr == %p\n", pr);


}