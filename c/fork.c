#include<stdio.h>
void main()
{
	printf("hello\n");
	if(1)
	{
		//printf("hi1\n");
		fork();
		printf("if part\n");

	}
	else
		printf("else part\n");
	printf("main\n");
}
