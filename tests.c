#include <stdio.h>
#include "functions.h"


int test_print(unsigned int number, int base, int sign, const char *expected) {
    printf("Number: %u, Base: %d, Sign: %d -> ", number, base, sign);
    printInBase(number, base, sign);
    return 1;
}

int main() {
    int all_passed = 1;

    all_passed &= test_print(0, 2, 1, "0");
    all_passed &= test_print(15, 2, 1, "1111");
    all_passed &= test_print(255, 16, 1, "FF");
    all_passed &= test_print(2748, 16, 1, "ABC");
    all_passed &= test_print(436851, 13, 1, "123ABC");
    all_passed &= test_print(123, 10, -1, "-123");
    all_passed &= test_print(35, 36, 1, "Z");

    if (all_passed) {
        printf("\nAll tests passed!\n");
    } else {
        printf("\nSome tests failed!\n");
    }

    return 0;
}
