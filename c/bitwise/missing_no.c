#include <stdio.h>

int find_missing(int arr[], int n) {
    int total_xor = 0;
    int array_xor = 0;

    for (int i = 1; i <= n; i++) {
        total_xor ^= i;
    }

    for (int i = 0; i < n - 1; i++) {
        array_xor ^= arr[i];
    }

    return total_xor ^ array_xor;
}

int main() {
    int arr[] = {1, 2, 4, 5};  // Missing number is 3
    int n = 5;  // Should include all numbers from 1 to 5

    int missing = find_missing(arr, n);
    printf("Missing number is: %d\n", missing);

    return 0;
}

