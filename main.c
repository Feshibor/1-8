#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "functions.h"

int main() {
    int base = 0;
    long number = 0; 
    char stop[4] = {'\0','\0','\0','\0'};
    long *numbers = NULL;
    int size = 0;
    int head = 0;
    int ch;
    
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (ch >= '0' && ch <= '9') {
            base = base * 10 + (ch - '0');
        } else {
            printf("BASE NUMBER ERROR\n");
            return 12;
        }
    }
    
    if (base < 2 || base > 36) {
        printf("BASE ERROR\n");
        return 1;
    }
    
    while (!(stop[0]=='S' && stop[1]=='t' && stop[2]=='o' && stop[3]=='p')) {
        int sign = 1;
        while ((ch = getchar()) != '\n' && ch != EOF) {
            stop[0] = stop[1];
            stop[1] = stop[2];
            stop[2] = stop[3];
            stop[3] = ch;
            
            if (ch >= '0' && ch <= '9') {
                head = ch - '0';
                number = number * base + head;
            }
            else if (ch >= 'A' && ch <= 'Z') {
                head = ch - 'A' + 10;
                number = number * base + head;
            }
            else if (ch >= 'a' && ch <= 'z') {
                head = ch - 'a' + 10;
                number = number * base + head;
            }
            else if (ch == '-' && number == 0) {
                sign = -1;
            }
            else {
                printf("INVALID CHARACTER ERROR\n");
                free(numbers);
                return 1;
            }
        }
        
        if (number != 0) {
            number *= sign;
            long *temp = realloc(numbers, (size + 1) * sizeof(long));
            if (!temp) {
                printf("MEMORY ALLOCATION ERROR\n");
                free(numbers);
                return 1;
            }
            numbers = temp;
            numbers[size] = number;
            size++;
            number = 0; 
        }
    }
    
    size--;
    int max = 0;
    int sign = 1;
    for (int i = 0; i < size; i++) {
        if(abs(numbers[i]) > max){
            max = abs(numbers[i]);
            if (numbers[i] < 0){
                sign = -1;
            } else {
                sign = 1;
            }
        }
    }

    printInBase(max, 9, sign);
    printInBase(max, 18, sign);
    printInBase(max, 27, sign);
    printInBase(max, 36, sign);
    
    free(numbers);
}
