#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    
    int *a,i,j,k,l,p,sum=0,ele,n;
    printf("enter the ele size\n");
    scanf("%d",&n);
    a=malloc(sizeof(int)*n);
    printf("enter the ele\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    sum=sum+a[i];
    free(a);
    printf("output=%d\n",sum);
    
    return 0;
    
}
