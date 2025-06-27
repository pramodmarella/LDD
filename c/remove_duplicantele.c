#include <stdio.h>

#define MAX 1000 // Assumes elements are in range 0 to 999

void removeDuplicates(int arr[], int size) {
    int seen[MAX] = {0}; // Flag array to track seen elements
    int i, j = 0;

    for (i = 0; i < size; i++) {
        if (seen[arr[i]] == 0) {
            seen[arr[i]] = 1;
            arr[j++] = arr[i]; // Keep the element
        }
        // If seen[arr[i]] is 1, we skip adding it again
    }

    // Print the array after removing duplicates
    for (i = 0; i < j; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {3, 5, 3, 2, 4, 5, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    removeDuplicates(arr, size);
    return 0;
}
