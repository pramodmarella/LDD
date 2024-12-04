#include<stdio.h>
int main()
{
	char a[20],i=5;
	snprintf(a,2,"%d",i);
	printf("%d\n",a[0]);
}
