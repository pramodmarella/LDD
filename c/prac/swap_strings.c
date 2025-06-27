#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int swap_str(char *m,char *r,int f,int l)
{
	int i,j,k,p,n,ind;
	char temp[200];
	int lr=strlen(r);
	int lm=strlen(m);
	for(i=l,k=0;m[i];i++)
		temp[k++]=m[i];
	temp[k++]='\0';
	for(i=f,j=l,p=0;r[p];p++,i++)
	{
		m[i]=r[p];
		 ind=i;
	}
	printf("index========>> %d\n",ind);
	for(n=0;temp[n];n++)
		m[i++]=temp[n];
	m[i++]='\0';
return ind;
}
void main()
{
	char *m,*r,*s;
	char temp[200];
	m=malloc(sizeof(char));
	s=malloc(sizeof(char));
	r=malloc(sizeof(char));
	printf("enter the main ,sub and replace string\n");
	scanf("%[^\n]%s%s",m,s,r);
	int i,j,k,p,l,n,o,f=0,l1,a,c=0;
	for(i=0;m[i];i++)
	{
		printf("c=%d\n",++c);
		for(j=i,p=0;m[j];j++)
		{
			if(m[j]==' ')
				break;
			temp[p++]=m[j];
		}
		printf("temp=====%s i==%d j==%d\n",temp,i,j);
		sleep(1);
		if(strcmp(temp,r)==0)
		{
		       int ind=swap_str(m,s,i,j);
		       printf("r =====%d\n",ind);
			int dif;
			int lr=strlen(r);
			int lm=strlen(s);
				sleep(1);
				i=ind+1;
		}
		else if(strcmp(temp,s)==0)
		{
			int ind=swap_str(m,r,i,j);
		       printf("s=====%d\n",ind);
			int dif;
			int lr=strlen(r);
			int lm=strlen(s);
				sleep(1);
				i=ind+1;
		}
		temp[0]='\0';
	printf("main==%s\n",m);
	}

}
