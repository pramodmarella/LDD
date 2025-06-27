#include<stdio.h>

void rec_rev(char *p,char *m)
{
	static int i,j,k,f=1;
	if(*p!=0)
	{
		rec_rev(p+1,m);
		printf("s=%c\n",*p);
	}
/*if(p<m)
{
	*p=*p+*m;
	*m=*p-*m;
	*p=*p-*m;
	rec_rev(++p,--m);
}
*/
}
void main()
{
	char s[20];
	printf("enter the string\n");
	scanf("%[^\n]",s);
	int i,j,k,p;
	for(k=0;s[k];k++);
/*	for(i=0,j=k-1;i<j;i++,j--)
	{
		s[i]=s[i]^s[j];
		s[j]=s[i]^s[j];
		s[i]=s[i]^s[j];
	}*/
	rec_rev(s,s+k-1);
//	printf("s==%s\n",s);
		
}
