#include <stdio.h>

// Function to print binary form of a number
void print_binary(int num) {
    for (int i = 7; i >= 0; i--) {  // adjust for number of bits as needed
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int clear_bits(int num, int start, int end) {
    int mask = ~(((1 << (end - start + 1)) - 1) << start);
    return num & mask;
}

int main() {
    int num = 5;         // Binary: 0b01000011
    int start = 0, end = 2;

    printf("Original: %d (0x%X) => Binary: ", num, num);
    print_binary(num);

    int result = clear_bits(num, start, end);

    printf("Modified: %d (0x%X) => Binary: ", result, result);
    print_binary(result);

    return 0;
}

