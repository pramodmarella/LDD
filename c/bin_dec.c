#include<stdio.h>
void main()
{
	int num,r,r1,sum,c=0,j=1;
	printf("enter the number\n");
	scanf("%d",&num);
	for(sum=0 ; num; )
	{
		r=num%10;
		//r1=r<<c;
		sum=sum+r*j;
		//c++;
		//sum=sum+r1;
		j=j*2;
		num/=10;
	}
	printf("%d\n",sum);
}
