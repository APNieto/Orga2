#include <stdio.h>

extern int op(int a, int b);

int main() {

    int a;
    int b;
    printf("Enter a and b: \n");
    scanf("%d", &a);
    scanf("%d", &b);

    int c = op(a, b);
    printf("Result: %d\n", c);

    return 0;

}