#include <stdio.h>

void print_binary(int num) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int set_bits(int num, int start, int end) {
    int mask = ((1 << (end - start + 1)) - 1) << start;
    return num | mask;
}

int main() {
    int num = 128;         // 0b01000011
    int start = 1, end = 4;

    printf("Original: %d (0x%X) => Binary: ", num, num);
    print_binary(num);

    int result = set_bits(num, start, end);

    printf("Modified: %d (0x%X) => Binary: ", result, result);
    print_binary(result);

    return 0;
}

