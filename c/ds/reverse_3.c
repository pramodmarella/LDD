#include<stdio.h>
#include<stdlib.h>
int l=0;
typedef struct stu
{
	int ID;
	struct stu *next;
}stu;
stu * reverse_list(stu * head,int k,int z)
{
	if(!head)
		return head;
	stu *t=head;
	stu *m=NULL;
	while(z--)
	{
		int count=0;
		stu *p=NULL,*n=NULL;
		while(t!=NULL && count<k)
		{
			n=t->next;
			t->next=p;
			p=t;
			t=n;
			count++;
		}
		stu *b=p;
		while(p->next!=NULL)
			p=p->next;
		p->next=n;
		stu *t11=p;
		while(t11!=NULL)
		{
			printf("%d ",t11->ID);
			t11=t11->next;
		}
		printf("\nejdffff\n");
		t=n;
		m=p;
	}

	/*	if(n!=NULL && z>=1)
		{
		head->next=reverse_list(n,k,z);
		}
		else
		{
		stu *b=p;
		while(p->next!=NULL)
		{
		p=p->next;
		}
		p->next=n;
		return b;
		}*/
	return m;
}
stu * create_node()
{
	stu * N=(stu *)malloc(sizeof(stu));
	printf("enter the ID\n");
	scanf("%d",&N->ID);
	N->next=NULL;
	return N;
}
stu * create_list()
{
	stu *H=NULL,*N=NULL,*L=NULL;
	char c='y';
	while(c=='y')
	{
		N=create_node();
		l++;
		if(H==NULL)
			H=N;
		else
			L->next=N;
		L=N;
		printf("do u want to create one more node y or n:\n");
		scanf(" %c",&c);
	}
	return H;
}
stu * Traversal(stu * T)
{
	while(T)
	{
		printf("%d ",T->ID);
		T=T->next;
	}
}
stu * reverse(stu * t)
{
	stu *p=t, *q=t,*r=t;
	q=q->next;
	r=q->next;
	while(q)
	{
		q->next=p;
		p=q;
		q=r;
		if(r)
			r=r->next;
	}
	t->next=NULL;
	return p;

}

int main()
{
	stu *H=NULL;
	H=create_list();
	printf("before reverse:\n");
	Traversal(H);
	printf("\nAfter reversing the linked list:\n");
	H=reverse(H);
	Traversal(H);
	printf("\nenter the num of elements to be reversed:\n");
	int x;
	scanf("%d",&x);
	int num=l/x;
	if(l>x)
	{
		H=reverse_list(H,x,num);
	}
	printf("\nAfter reversing:\n");
	Traversal(H);
}
