#include <stdio.h>
#include "functions.h"

void printInBase(unsigned int number, int base, int sign) {
    unsigned int div = 1;
    while (number / div >= (unsigned int)base) {
        div *= base;
    }
    if (sign < 0) {
        printf("-");
    }
    while (div > 0) {
        int head = number / div;
        if (head < 10)
            printf("%c", '0' + head);
        else
            printf("%c", 'A' + (head - 10));
        number %= div;
        div /= base;
    }
    printf("\n");
}