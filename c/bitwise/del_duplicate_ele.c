#include <stdio.h>

int removeDuplicates(int arr[], int n) {
    int bitset = 0;
    int index = 0; 

    for (int i = 0; i < n; i++) {
        int val = arr[i];
        if (!(bitset & (1 << val))) {
            bitset |= (1 << val);
            arr[index++] = val;  
        }
    }

    return index;  
}

int main() {
    int arr[] = {1, 3, 5, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int newSize = removeDuplicates(arr, n);

    printf("Array after removing duplicates: ");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

