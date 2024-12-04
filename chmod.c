#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <time.h>
void main(int argc,char **argv)
{
	struct stat v;
	if(stat(argv[1],&v)<0)
	{
		perror("stat:");
		return;
	}
		perror("stat:");
	printf("%o ",v.st_mode&0777);

	chmod(argv[1],0661);
	stat(argv[1],&v);
		perror("chmod:");
	printf("%o ",v.st_mode&0777);

}
