#include<stdio.h>
#include<string.h>
int rec_len(char *s)
{
	static int l=0;
	if(*s)
	{
		l++;
		rec_len(++s);
	}
	else
		return l;

}
void main()
{
	int l=rec_len("hello");
	printf("l=%d\n",l);
	printf("strlen=%ld\n",strlen("hello"));
	printf("sizeof=%ld\n",sizeof("hello"));

}
