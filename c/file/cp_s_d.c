#include<stdio.h>
void main(int argc,char **argv)
{
	FILE *df,*sf;
	sf=fopen(argv[1],"r");
	df=fopen(argv[2],"w");

	char ch;
	int i;
	while((ch=fgetc(sf))!=-1)
	{
		fputc(ch,df);
	}
	
}
