#include <stdio.h>

void main() {
    int a[5], i, ele;
    ele = sizeof(a) / sizeof(a[0]);

    printf("Enter the elements:\n");
    for (i = 0; i < ele; i++) {
        scanf("%d", &a[i]);
    }

    int pos = 0; 

    for (i = 0; i < ele; i++) {
        if (a[i] % 2 == 0) {
            int temp = a[i];
            a[i] = a[pos];
            a[pos] = temp;
            pos++;
        }
    }

    printf("evens first:\n");
    for (i = 0; i < ele; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}


/*
#include<stdio.h>
void main()
{
	int a[5],i,j,ele;
	ele=sizeof(a)/sizeof(a[0]);
	printf("enter the ele\n");
	for(i=0;i<ele;i++)
	{
		scanf("%d",&a[i]);
	}

	for(i=0;i<ele;i++)
	{
		for(j=0;j<ele;j++)
		{
			if(a[i]%2==0)
			{
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}

	for(i=0;i<ele;i++)
		printf("%d ",a[i]);
	printf("\n");
}*/
