#include <stdio.h>

int main(){
	int T,N,k;
	printf("enter the text cases\n");
	scanf("%d", &T);    
	while(T!=0) 
	{         	                  // Reading input from STDIN
	printf("enter the elements and rotations times\n");      // Writing output to STDOUT
	scanf("%d %d",&N,&k);
	int a[N],ele,i,t,p;
	ele=sizeof(a)/sizeof(a[0]);
	for(i=0;i<ele;i++)
	scanf("%d",&a[i]);
	for(p=0;p<k;p++)
	{
		int t=a[ele-1];
		for(i=ele-1;i>=0;i--)
		{
			a[i]=a[i-1];

		}
		a[0]=t;

	}
	for(i=0;i<ele;i++)
	printf("%d ",a[i]);
	printf("\n");
	T--;
	}
}

