#include<stdio.h>
void main()
{
	int a[2][2],t[2][2],i,j,k,l,p;

	printf("enter the matrix ele\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
			scanf("%d",&a[i][j]);
	}
	printf("printing the matrix\n");
	
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}

	for(i=0;i<2;i++)
	{
		for(j=0;j<i;j++)
		{
			p=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=p;
		}
	}
		printf("\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}
