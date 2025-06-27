#include <stdio.h>

unsigned int reverseBits(unsigned int n) {
    n = (n >> 1)  & 0x55555555 | (n & 0x55555555) << 1;
    n = (n >> 2)  & 0x33333333 | (n & 0x33333333) << 2;
    n = (n >> 4)  & 0x0F0F0F0F | (n & 0x0F0F0F0F) << 4;
    n = (n >> 8)  & 0x00FF00FF | (n & 0x00FF00FF) << 8;
    n = (n >> 16) & 0x0000FFFF | (n & 0x0000FFFF) << 16;
    return n;
}

void printBinary(unsigned int n) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
        if (i % 8 == 0) printf(" ");
    }
    printf("\n");
}

int main() {
    unsigned int num;
    printf("Enter an unsigned integer: ");
    scanf("%u", &num);

    printf("Original (binary):   ");
    printBinary(num);

    unsigned int reversed = reverseBits(num);

    printf("Reversed (binary):   ");
    printBinary(reversed);
    printf("Reversed (decimal):  %u\n", reversed);

    return 0;
}

