#include<stdio.h>
void main()
{
	int a[2][2],b[2][2],r[2][2];
	int i,j,k,p,m;
	printf("enter the matrix\n");
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			scanf("%d",&b[i][j]);
	printf("before printing\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
			printf("%d ",b[i][j]);
		printf("\n");
	}
	if(2==2)
	{
		for(i=0;i<2;i++)
		{
			for(j=0;j<2;j++)
			{
				r[i][j]=0;
				for(k=0;k<2;k++)
					r[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
			printf("%d",r[i][j]);
		printf("\n");
	}
	
}
