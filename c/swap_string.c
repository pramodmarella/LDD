#include<stdio.h>
void main()
{
	char s[10];
	printf("enter the string\n");
	scanf("%s",s);
	printf("%s\n",s);
	int i,j,k;
	int l;
	for(l=0;s[l];l++);
	for(i=0,j=l-1;i<j;i++,j--)
	{
	/*	s[i]=s[i]^s[j];
		s[j]=s[i]^s[j];
		s[i]=s[i]^s[j];*/
		s[i]^=s[j]^=s[i]^=s[j];
	}
	printf("s==%s\n",s);
}
