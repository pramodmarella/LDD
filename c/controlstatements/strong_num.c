#include<stdio.h>
void main()
{
	int num,num1,i,j,k,f,p,m,sum,c;
	printf("enter the number\n");
	scanf("%d",&num);
	for(;num<100000;num++)
	{
		for(num1=num,sum=0,c=0;num1;num1/=10)
		{
			p=num1%10;
			for(f=1;p>0;p--)
				f=f*p;
			sum=sum+f;
		}
		if(sum==num)
			printf("strong no=%d\n",sum);
	}
}
