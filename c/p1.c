#include<stdio.h>
#include<stdlib.h>
void main()
{
	int *p;
	p=malloc(sizeof(int *));
	*p=20;
	printf("*p==%d\n",*p);
	free(p);
	printf("*p==%d\n",*p);
	free(p);
/*char str[] = "ABCDEFG";
memmove(str , str +2, 5);  // Safe: shifts "ABCDE" to right inside same array
printf("str==%s\n",str);
*/
//printf("com==%d\n",~1);
}
