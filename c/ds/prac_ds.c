#include<stdlib.h>
#include<unistd.h>

#include<stdio.h>
typedef struct st
{
	int rollno;
	struct st *next;
}sll;

void add_begin(sll **ptr)
{
	sll *new;
	new=malloc(sizeof(sll));
	printf("enter the rollno\n");
	scanf("%d",&new->rollno);

	new->next=*ptr;
	*ptr=new;
}

void print_node(sll *ptr)
{
	while(ptr)
	{
		printf("rollno-->%d\n",ptr->rollno);
		ptr=ptr->next;
	}
}

void callback(sll **hp, void (*p)(sll** ))
{
	return p(hp);
}

void find_middle_node(sll **ptr)
{
	sll *t=*ptr,*t1=*ptr;
	while(t1&& t1->next!=0)
	{
		t1=t1->next->next;
//		t1=t1->next;
		t=t->next;
	}
printf("middle node==>%d\n",t->rollno);
	
}

void reverse(sll **hp)
{
    sll *prev = NULL;
    sll *cur = *hp;
    sll *next = NULL;
printf("in function\n");
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev; 
        prev = cur;     
        cur = next;
    }
    *hp = prev; 
}
/*void reverse(sll **hp)
{
	sll *n=0,*t=*hp,*prev=0;
	while(t !=NULL)
	{
		n=t->next;
		t->next=prev;
		prev=t;
		t=n;	
	}
*hp=prev;
}*/

void main()
{
	sll *hp=0;
	int op;
	void (*p)(sll**);
	while(1)
	{
		printf("enter the option\n1)insert the node\n2)print\n6)reverse\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:add_begin(&hp);
			break;
			case 2:print_node(hp);
			break;
			case 3:p=add_begin;
				p(&hp);
				break;
			case 4:callback(&hp,add_begin);
			break;
			case 5:find_middle_node(&hp);
			break;
			case 6:reverse(&hp);
			break;
			case 16:exit(0);

		}
	}
}
