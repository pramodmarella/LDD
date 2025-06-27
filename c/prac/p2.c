#include<stdio.h>
void main()
{
	int num,i,j,k,l,p,m=0,h;
	printf("enter the num\n");
	scanf("%d",&num);
	p=l=1,k=1;
	for(i=0,m=1;i<num;i++,p=(++p)+k,m++)
	{
		for(j=0,l=p,h=m;j<num;j++,l++,h=h+j)
		{
			printf("%d",h);
		}
printf("\n");
	}
}
