#include<stdio.h>
void main()
{
	int a[5],i,j,k,lar;
	printf("enter the number\n");
	int ele=sizeof(a)/sizeof(a[0]);
	for(i=0;i<ele;i++)
	scanf("%d",&a[i]);
	lar=-1;
	int num;
	int sum;
	for(i=0;i<ele;i++ )
	{
		for(num=a[i],sum=0; num; num/=10)
		{
			sum=sum*10+num%10;		
		}
		if(sum==a[i])
		{
			if(a[i]>lar)
			{
				lar=a[i];
				printf("lar ===%d ",lar);
			}
		}
	}
//	printf("lar==%d\n",lar);
}
