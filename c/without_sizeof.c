#include <stdio.h>

struct Sample {
    char a;
    short int b;
    int i;
    int p;
    double c;
};

int main() {
    struct Sample *ptr1 = NULL;
    struct Sample *ptr2 = ptr1 + 1;  // Move one struct ahead

    int size = (char *)ptr2 - (char *)ptr1;  // Pointer difference in bytes

    printf("Size of struct Sample is: %d bytes\n", size);

    return 0;
}

