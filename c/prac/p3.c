#include<stdio.h>
void main(extern int argc)
{
	static int y;
	y=argc;
	printf("%d\n",y);

}
