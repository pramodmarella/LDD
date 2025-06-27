#include<stdio.h>
	const int a=20;
void main()
{
	int *p=&a;
	*p=60;
	printf("%d %d\n",*p,a);
}
