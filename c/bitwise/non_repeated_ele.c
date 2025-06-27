#include<stdio.h>
int findSingle(int arr[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result ^= arr[i];
    }
    return result;
}

int main() {
    int arr[] = {2, 3, 5,5, 4, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The non-repeating element is: %d\n", findSingle(arr, n));
    return 0;
}


/*void main()
{
	int a[6],i,j,k,l,ele=6;
	printf("enter the ele\n");
	for(i=0;i<ele;i++)
		scanf("%d",&a[i]);
	int sum=0;
	for(i=0;i<ele;i++)
	{
		sum^=a[i];
	}
	printf("%d\n",sum);
}*/
