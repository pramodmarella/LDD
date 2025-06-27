#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int swap_str(char *m, char *r, int f, int l) {
    char temp[1000];  // enough to hold the rest of the string
    int i, j, k = 0;

    // Copy rest of the string after l
    for (i = l; m[i]; i++)
        temp[k++] = m[i];
    temp[k] = '\0';

    // Replace word in m from index f
    for (i = f, j = 0; r[j]; j++, i++)
        m[i] = r[j];
    
    int new_end = i;

    // Append the rest of original string
    for (k = 0; temp[k]; k++)
        m[i++] = temp[k];
    m[i] = '\0';

    return new_end;
}

int main() {
    char *m = malloc(1000);
    char *s = malloc(100);
    char *r = malloc(100);
    char temp[100];

    printf("Enter main string: ");
    fgets(m, 1000, stdin);
    m[strcspn(m, "\n")] = '\0';  // Remove newline

    printf("Enter first word to swap: ");
    scanf("%99s", s);

    printf("Enter second word to swap: ");
    scanf("%99s", r);

    int i = 0;
    while (m[i]) {
        int start = i, j = 0;

        // Extract word
        while (m[i] && m[i] != ' ')
            temp[j++] = m[i++];
        temp[j] = '\0';

        // Check for exact match
        if (strcmp(temp, s) == 0) {
            i = swap_str(m, r, start, i);
        } else if (strcmp(temp, r) == 0) {
            i = swap_str(m, s, start, i);
        }

        if (m[i] == ' ')
            i++;
    }

    printf("Resulting string: %s\n", m);

    free(m);
    free(s);
    free(r);
    return 0;
}

