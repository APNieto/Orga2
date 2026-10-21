#include <stdio.h>

#define s 100

void print1(int arr[s]) {
    printf("arr[2] == %d\n", arr[2]);
    printf("sizeof(arr) == %zu\n", sizeof(arr));
}

void print2(int *arr) {
    printf("arr[2] == %d\n", arr[2]);
    printf("sizeof(arr) == %zu\n", sizeof(arr));
}

int main(){

    int a[s] = {0};
    a[2] = 12;
    print1(a);
    print2(a);

}