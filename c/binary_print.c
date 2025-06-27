#include<stdio.h>

#include <stdio.h>

unsigned int ReverseTheBits(unsigned int x)
{
    x = ((x & 0xAAAAAAAA) >> 1) | ((x & 0x55555555) << 1);
    x = ((x & 0xCCCCCCCC) >> 2) | ((x & 0x33333333) << 2);
    x = ((x & 0xF0F0F0F0) >> 4) | ((x & 0x0F0F0F0F) << 4);
    x = ((x & 0xFF00FF00) >> 8) | ((x & 0x00FF00FF) << 8);
    x = (x >> 16) | (x << 16);
    return x;
}

int main()
{
    int num = 1,pos;  
    int reversed = ReverseTheBits(num);

    printf("Original: %u\n", num);
	for(pos=31;pos>=0;pos--)
	{
		printf("%d",num>>pos&1);
		if(pos%4==0)
			printf("  ");
	}
	printf("\n");
	num=reversed;
	for(pos=31;pos>=0;pos--)
	{
		printf("%d",num>>pos&1);
		if(pos%4==0)
			printf("  ");
	}

	printf("\n");
    printf("Reversed: %u\n", reversed);
    return 0;
}

/*void main()
{
	int pos=31;
	int num,b=20;
	printf("enter the number\n");
	scanf("%d",&num);
//	num=( num+ ((~b)+ (-1)) );
	printf("num==%d\n",num);
//	num=num|(num+1);
	for(pos=31;pos>=0;pos--)
	{
		printf("%d",num>>pos&1);
		if(pos%4==0)
			printf("  ");
	}
	printf("\n");
}
*/
/*
#include <stdio.h>

void main()
{
    int num;
    printf("Enter the number:\n");
    scanf("%d", &num);

    unsigned int mask = 1 << 31; 
    for (int i = 0; i < 32; i++)
    {
        printf("%d", (num & mask) ? 1 : 0);
        if ((31 - i) % 4 == 0)
            printf("  ");
        mask >>= 1;
    }
    printf("\n");
}*/
