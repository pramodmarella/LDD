#include <stdio.h>

// Bitwise addition (no +)
int bitwise_add(int a, int b) {
    while (b != 0) {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

// Bitwise subtraction: a - b using only bitwise (without defining negate separately)
int bitwise_subtract(int a, int b) {
    while (b != 0) {
        int borrow = (~a) & b;
        a = a ^ b;
        b = borrow << 1;
    }
    return a;
}

int main() {
    int a = 15;
    int b = 8;
	int result=bitwise_add(a,b);

    printf("Bitwise addition of %d + %d = %d\n", a, b, result);
     result = bitwise_subtract(a, b);

    printf("Bitwise Subtraction of %d - %d = %d\n", a, b, result);

    return 0;
}

