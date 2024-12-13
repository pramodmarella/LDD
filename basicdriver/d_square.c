#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdlib.h>
int main(int argc,char **argv)
{
	int fd;
	char s[20];
	fd=open(argv[1],O_WRONLY,0664);
//	printf("enter the data\n");

	write(fd,argv[2],strlen(argv[2])+1);
	close(fd);
	fd=open(argv[1],O_RDONLY,0664);
	read(fd,s,sizeof(s));
	int double1=atoi(s);	
	printf("result=%d\n",double1);
	close(fd);
}
