#include <stdio.h>

void findDuplicates(int arr[], int n) {
    int bitset = 0;

    for (int i = 0; i < n; i++) {
        int val = arr[i];
        if (bitset & (1 << val)) {
            printf("Duplicate found: %d\n", val);
        } else {
            bitset |= (1 << val);
        }
    }
}

int main() {
    int arr[] = {1, 3, 5, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    findDuplicates(arr, n);
    return 0;
}
