#include<stdio.h>
#include<stdlib.h>
void setbit(int x,int pos)
{
	int pow=1;
	for(int i=0;i<pos;i++)
	{
		pow*=2;
	}
	printf("%d",(x+(x/pow%2==0?pow:0)));
}

void clrbit(int x,int pos)
{
	int pow=1;
	for(int i=0;i<pos;i++)
	{
		pow*=2;
	}
	printf("%d",(x-(x/pow%2==1?pow:0)));
}

void toggle(int x,int pos)
{
	int pow=1;
	for(int i=0;i<pos;i++)
	{
		pow*=2;
	}
	printf("%d",(x+(x/pow%2==0?pow:-pow)));
}
int main()
{
	int x,pos;
	printf("enter the num :\n");
	scanf("%d",&x);
	printf("enter the position to set:\n");
	scanf("%d",&pos);
	setbit(x,pos);
	clrbit(x,pos);
	toggle(x,pos);
}
