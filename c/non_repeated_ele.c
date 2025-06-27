#include <stdio.h>

#define MAX 1000 // Assumes elements are in range 0 to 999

void removeDuplicates(int arr[], int size) {
    int seen[MAX] = {0}; // Flag array to track seen elements
    int i, j = 0;

    for (i = 0; i < size; i++) {
	    seen[arr[i]]++;
        }

    for (i = 0; i < size; i++) {
	    if(seen[arr[i]]==1)
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {3, 5, 3, 2, 4, 5,10};
    int size = sizeof(arr) / sizeof(arr[0]);

    removeDuplicates(arr, size);
    return 0;
}
