// Forced errors to be checked with valgrind

#include <stdio.h>

int main() {
    int nums[10] = {0};
    int num1 = nums[11];
    printf("pim");
}