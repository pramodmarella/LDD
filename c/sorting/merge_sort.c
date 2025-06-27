#include<stdio.h>
void merge(int *p,int lb,int mid,int ub)
{
	int i,k;
	i=k=lb;
	int j=mid+1;
	int b[ub];
	while(i<=mid && j<=ub)
	{
		if(p[i]<=p[j])
			{
				b[k]=p[i];
				i++;
			}
		else
		{
			b[k]=p[j];
			j++;
		}
		k++;
	}
	if(i>mid)
	{
		while(j<=ub)
		{
			b[k]=p[j];
			j++;
			k++;
		}

	}
	else
	{
		while(i<=mid)
		{
			b[k]=p[i];
			i++;
			k++;
		}
	}
	for(k=lb;k<=ub;k++)
		p[k]=b[k];

}
void merge_sort(int *p,int lb,int ub)
{
	int i,j,k,mid;
	if(lb<ub)
	{
		mid=(lb+ub)/2;
		merge_sort(p,lb,mid);
		merge_sort(p,mid+1,ub);
		merge(p,lb,mid,ub);

	}
}

void main()
{
	int a[5],i,j,k,ele,p;
	ele=sizeof(a)/sizeof(a[0]);
	printf("enter the ele 's \n");
	for(i=0;i<ele;i++)
		scanf("%d",&a[i]);
	merge_sort(a,0,ele-1);
	for(i=0;i<ele;i++)
		printf("%d ",a[i]);
	printf("\n");

}
