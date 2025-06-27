#include <stdio.h>

void bubbleSortOneLoop(int arr[], int n) {
    int i = 0;
    while (i < n - 1) {
        if (arr[i] > arr[i + 1]) {
            // Swap
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
            // Restart from beginning
            i = 0;
        } else {
            i++;
        }
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSortOneLoop(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

