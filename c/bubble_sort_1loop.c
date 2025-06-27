#include <stdio.h>

void bubbleSortOneLoop(int arr[], int n) {
    int i = 0, j = 0, temp;
    
    for (int k = 0; k < n * n; k++) {
        if (arr[j] > arr[j + 1]) {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }

        j++;

        if (j >= n - i - 1) {
            j = 0;
            i++;
        }

        if (i >= n - 1) {
            break;
        }
    }
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSortOneLoop(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

