#include<stdio.h>
void main()
{
	int a[5],i,j,k,l;
	int ele=5;
	printf("enter the ele's \n");
	for(i=0;i<ele;i++)
	scanf("%d",&a[i]);

	for(i=0;i<ele;i++)
	{
		for(j=i+1;j<ele;j++)
		{
			if(a[i]>a[j])
			{
				k=a[i];
				a[i]=a[j];
				a[j]=k;
			}
		}
	}
	for(i=0;i<ele;i++)
		printf("%d\t",a[i]);
}
