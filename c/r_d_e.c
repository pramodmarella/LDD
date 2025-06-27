#include<stdio.h>
void main()
{
	int a[10]={1,2,1,2,4,3,3,2,3,2};
	int ele=10,i,j;
 	int b[1000]={0};
	//printf("%d\n",b[0]);
	for(i=0,j=0;i<ele;i++)
	{
		if(b[a[i]]==0)
		{
			b[a[i]]=1;
			a[j++]=a[i];
		}
	}
	for(i=0;i<j;i++)
		printf("%d ",a[i]);
	printf("\n");
	
}
