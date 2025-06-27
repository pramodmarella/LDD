#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i,j,k;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }
    int len=0;
    for(len=0;arr[len];len++);
    /* Write the logic to reverse the array. */
 for(i=0,j=len-1;i<j;i++,j--)
    {
        k=arr[i];
        arr[i]=arr[j];
        arr[j]=k;
    }
    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}
