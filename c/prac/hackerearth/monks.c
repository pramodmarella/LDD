#include <stdio.h>
int inversions(int n, int matrix[n][n]) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int p = i; p < n; p++) {
                for (int q = j; q < n; q++) {
                    if (matrix[i][j] > matrix[p][q]) {
                        count++;
                    }
                }
            }
        }
    }

    return count;
}

int main() {
    int T;
    scanf("%d", &T); 

    while (T--) {
        int N;
        scanf("%d", &N); 

        int matrix[N][N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }

        printf("%d\n", inversions(N, matrix));
    }

    return 0;
}

