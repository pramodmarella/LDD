#include<stdio.h>
void main()
{
	int a[5],i,j,k,l,m,p,ele=5,f;
	printf("enter the ele\n");
	for(i=0;i<ele;i++)
	scanf("%d",&a[i]);

	for(i=0,k=i;i<ele;i++)
	{
		if(a[i+1]==a[k])
		{
			f=1;
			a[i]=a[i+1];
			if(i==ele-1)
			{
				i=k;
				k++;
			}

		}
		else if(f==1)
		{
			f=0;
			
		}
		else
		{
			if(i==ele-1)
			{
				i=k;
			}
		}
	}
	for(i=0;i<ele;i++)
		printf("%d",a[i]);
	printf("\n");
}
