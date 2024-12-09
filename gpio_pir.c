#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
void main()
{
	int fd=open("/dev/gpio_2",O_RDONLY);
	int data;
	char s[2];
	read(fd,&data,4);
	close(fd);
	data=data-48;
	snprintf(s,2,"%d",data);
	s[1]='\0';
	fd=open("/dev/gpio_2",O_WRONLY);
	write(fd,s,strlen(s)+1);
	printf("data=%d\n",data);
	close(fd);
}
