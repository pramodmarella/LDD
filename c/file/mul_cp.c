#include<stdio.h>
void main(int argc,char **argv)
{
	FILE *sf,*df;
	char ch;
	sf=fopen(argv[1],"r");
//	df=fopen(argv[2],"w");
	for(int i=2;i<argc;i++)
	{
		df=fopen(argv[i],"w");
		while( (ch=fgetc(sf))!=-1 )
			fputc(ch,df);
		rewind(sf);

	}
	
}
