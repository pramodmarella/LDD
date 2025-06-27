#include<stdio.h>
void main()
{
	char num;
	int p1,p2,c,i,j,k,p;
	printf("enter the num,start and stop position , range\n");
	scanf("%hhd%d%d%d",&num,&p1,&p2,&c);
	for(i=7;i>=0;i--)
	{
		printf("%d",num>>i&1);
		if(i%4==0)
			printf(" ");
	}
	int n1,n2;
	printf("\n");
	for(;p1<p2;p1=p1+c)
	{
		for(i=p1,j=p1+c-1;i<j;i++,j--)
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
	for(i=7;i>=0;i--)
	{
		printf("%d",num>>i&1);
		if(i%4==0)
			printf(" ");
	}

}
