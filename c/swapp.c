#include<stdio.h>
void main()
{
	int num;
	int p1,p2,c,i,j,k,p;
	printf("enter the num,start and stop position , range\n");
	scanf("%d%d%d%d",&num,&p1,&p2,&c);
	for(i=31;i>=0;i--)
	{
		printf("%d",num>>i&1);
		if(i%4==0)
			printf(" ");
	}
	int n1,n2;
	printf("\n");
	for(;p1<p2;p1=p1+j)
	{
		for(i=p1+1,k=i,j=i+c;i<(k+c);i++,j++)
		{
			n1=num>>i&1;
			n2=num>>j&1;
			if(n1!=n2)
			{
				num=num^1<<i;
				num=num^1<<j;
			}
		}
	}
	for(i=31;i>=0;i--)
	{
		printf("%d",num>>i&1);
		if(i%4==0)
			printf(" ");
	}

}
