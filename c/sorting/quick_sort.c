#include<stdio.h>
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
int partition(int *a,int lb,int ub)
{
	int pivot=a[lb];
	int start=lb;
	int end=ub;
	while(start<end)
	{
		while(a[start]<=pivot)
		{
			start++;
		}
		while(a[end]>pivot)
			end--;
		if(start<end)
			swap(&a[start] ,&a[end]);
	}
	swap(&a[lb],&a[end]);
		return end;

}
void quick_sort(int *a,int lb,int ub)
{
	if(lb<ub)
	{
		int loc=partition(a,lb,ub);
		quick_sort(a,lb,loc-1);
		quick_sort(a,loc+1,ub);
	}
}
void main()
{
	int a[5],i,j,k,l,p,ele;
	ele=sizeof(a)/sizeof(a[0]);
	
	printf("enter the ele 's\n");
	for(i=0;i<ele;i++)
		scanf("%d",&a[i]);
		printf("before\n");
	quick_sort(a,0,ele-1);
		printf("after \n");
	for(i=0;i<ele;i++)
	printf("%d ",a[i]);
	printf("\n");
}

