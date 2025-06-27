#include<stdio.h>
#include<stdlib.h>
void main()
{
	char *s,d[20]="hello";
	int i,j,k,l,m,n,o,p;
	s=malloc(sizeof(char));
	printf("enter the string\n");
	scanf("%[^\n]",s);
	printf("%s\n",s);

	for(i=0;i<s[i];i++)
	{
		if(s[i]==d[0])
		{
			for(j=1;d[j];j++)
			{
				if(s[j+i]!=d[j])
					break;
			}
			if(d[j]=='\0')
			{
				l=strlen(d);
				//for(p=0,o=i+j+1;p<l;p++)
				{
					for(n=i+j,m=i;s[n];m++,n++ )
						s[m]=s[n];
				s[m]='\0';
				printf("s==%s\n",s);
				sleep(1);
				}
				i--;

			}
		}
	}

}
