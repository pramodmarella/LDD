#include<stdio.h>
void main()
{
	int num,i,j,k,l,p;
	printf("enter the number\n");
	scanf("%d",&num);
	int sum=0;
	sum=num*num;
	p=num%100 + num/100;
	printf("sum=%d\n",p);
}
