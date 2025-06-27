#include<stdio.h>
void main()
{
	int num;
	int i,pos;
	printf("enter the num\n");
	scanf("%d",&num);
	for(pos=7;pos>=0;pos--)
		printf("%d",num>>pos&1);
	printf("\n");

num=((num & 0x0F) << 4) | ((num & 0xF0) >> 4);
	for(pos=7;pos>=0;pos--)
		printf("%d",num>>pos&1);
	printf("\n");
}
