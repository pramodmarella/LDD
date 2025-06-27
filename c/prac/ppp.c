#include<stdio.h>
//#define add(y) y*y

int sum(int *a)
{
	int sum=0;
//	size=sizeof(a)/sizeof(a[0]);
//	printf("size==>%d\n",size);
	int i;
	for(i=0;i<5;i++)
	{
		sum+=a[i];
//		printf("%d\n",sum);
	}
}

int main()
{
	int a[]={1,2,3,5,6,7,8,9};
	int s=sum(a);
	printf("%d \n",s);

/*int r=add((10+20)/5);
//printf("p==%d\n",r);
int a=4001;
int *p0=&a;
char *p1;
p1=(char*)p0;
printf("value of *p0=%d\n",*p0);
printf("value of *p1=%d\n",*p1);
return 0;*/
}
