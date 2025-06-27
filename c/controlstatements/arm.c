#include<stdio.h>
void main()
{
 int i,j,c,k,m,n,l,p,num,num1,sum;
 printf("enter the number\n");
 scanf("%d",&num);
// num1=num;
 for(;num<1000;num++)
 {
 for( c=0,num1=num;num1;num1/=10,c++);
 for(sum=0,num1=num;num1;num1/=10)
 {
	
	p=num1%10;
	for(l=1,m=c;m>0;m--)
		l=l*p;
	sum=sum+l;


 }
 if(sum==num)
	 printf("it is armstrong %d\n",sum);
}
}
