#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
typedef struct st
{
	int rollno;
	struct st *next;
}st;


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int getLength(st * head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

st* findIntersection(st*  head1, st * head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    if (len1 > len2) {
        while (diff--) head1 = head1->next;
    } else {
        while (diff--) head2 = head2->next;
    }

    
    while (head1 && head2) {
        if (head1 == head2)
            return head1; 
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL; 
}

void reverse_gen(st *pt)
{
/*	int num,i,j,k,p;
	printf("enter the num\n");
	scanf("%d",&num);

	st *temp=pt,*start=p;
	int c=count_node(pt);
	p=c/num;
	j=num;
	while(p>0)
	{
		while(j)
		{
			for(i=0;i<num-1-i;i++)
			{
				temp=temp->next;
			}

			
		}


		




		p--;

	}*/
}


int count_node(st *pt)
{
	int c=0;
	while(pt)
	{
		c++;
		pt=pt->next;
	}
	return c;
}

void del_middle(st **pt)
{
	st *temp=*pt,*del=*pt,*prev;
	int i,j,l,c=count_node(*pt);
	int middle;
	//	if (c%2==0) {
	//		middle=c/2;  
	//	} else {
	//		middle=c/2;     
	//	}
	for (i=0;i<c-1; i++) {
		prev=temp;
		temp=temp->next;
	}
	prev->next = temp->next;        
	free(temp);  
}



void add_begin(st **pt)
{
	st *new;
	new=malloc(sizeof(st));
	printf("enter the rollno\n");
	scanf("%d",&new->rollno);

	new->next=*pt;
	*pt=new;

}
void print_data(st *pt)
{
	if(pt==0)
	{
		printf("no records present\n");
		return;
	}
	while(pt)
	{
		printf("data=%d\n",pt->rollno);
		pt=pt->next;
	}
}
int main()
{
	st *hp=0,*hp1=0;
	int op;
	while(1)
	{
		printf("enter the options\n");
		printf("1)add_begin\n 2)print_data\n3)del_middle\n4)reve\n5)add_beginhp1\n6)hp1_print\n7)intersection\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:add_begin(&hp);
			       break;
			case 2:print_data(hp);
			       break;
			case 3:del_middle(&hp);
			       break;
			case 4:reverse_gen(hp);
			       break;
			case 5:add_begin(&hp1);
			       break;
			case 6:print_data(hp1);
			       break;
			case 7:st * r=findIntersection(hp,hp1);
				if(r)
					printf("intersection==%d\n",r->rollno);
				else
					printf("no intersection\n");
				break;
			case 0:exit(0);
			       break;
		}
	}
}
