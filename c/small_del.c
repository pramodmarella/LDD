#include<stdio.h>
void main()
{
	int num,i,j,k,l,p,s;
	printf("enter the number\n");
	scanf("%d",&num);
	s=num%10;
	int num1=num;
	for(;num;num/=10)
		if(num%10<s)
			s=num%10;
	printf("s==%d\n",s);
	for(p=1;num1;num1/=10)
	{
		if(s!=num1%10)
		{
			num=num+(num1%10)*p;
			p=p*10;
		}
		//else
		//	num=num*10+num1%10;
	}
	printf("num==%d\n",num);
}
