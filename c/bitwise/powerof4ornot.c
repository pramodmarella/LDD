#include <stdio.h>
#include <math.h>
int main() {
    // Write C code here
    //printf("Try programiz.pro");
    int n=16;
//int pos = log2(n & -n) + 1;
if ((n & (n - 1)) == 0 && (n & 0xAAAAAAAA) == 0)
    printf("Power of 4");

//printf("%d\n",pos);
    return 0;
}
