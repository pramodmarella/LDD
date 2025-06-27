#include <stdio.h>

// Function to print binary form of a number
void print_binary(int num) {
    for (int i = 31; i >= 0; i--) {  // adjust for number of bits as needed
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int toggle_bits(int num, int start, int end) {
    int mask = (((1 << (end - start + 1)) - 1) << start);
    return num ^ mask;
}

int main() {
    int num =15 ;         // Binary: 0b01000011
    int start = 0, end = 3;

    printf("Original: %d  => Binary: ", num);
    print_binary(num);

    int result = toggle_bits(num, start, end);

    printf("Modified: %d  => Binary: ", result);
    print_binary(result);

    return 0;
}

