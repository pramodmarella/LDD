#include<stdio.h>
struct
{
	char a[20];
	int b;
	union
	{
		double c;
		struct
		{
			char d[15];
			float e;
		}x;
	}y;
}z;
int main()
{
	printf("%d\n",sizeof(z.y.x));	
	printf("%d\n",sizeof(z.y));	
	printf("%d",sizeof(z));	
}
