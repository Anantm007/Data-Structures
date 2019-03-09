#include<iostream>

using namespace std;

class node
{
	public:
		int data;
		node *next;
		
		node(int d)
		{
			data=d;
			next=NULL;
		}
};


void inserttail(node *&head,int x)
{
	if(head==NULL)	//	Insert at head
	{
		node *n=new node(x);
		head=n;
		return;
	}
	
	
	//  Insert at tail
	node *t=head;
	while(t->next!=NULL)
	t=t->next;
	
	t->next=new node(x);
}


void buildlist(node *&head)
{
	inserttail(head,10);
	inserttail(head,50);
	inserttail(head,20);
	inserttail(head,30);
	inserttail(head,40);	
}


node *merge(node *a,node *b)
{
	if(a==NULL)
	return b;
	
	if(b==NULL)
	return a;
	
	node *c;
	
	if(a->data < b->data)
	{
		c=a;
		c->next=merge(a->next,b);
	}
	
	else
	{
		c=b;
		c->next=merge(a,b->next);
	}
}


node *midpoint(node *head)
{
	if(head==NULL || head->next==NULL)
	return head;
	
	node *slow=head;
	node *fast=head->next;
	
	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	
	return slow;	
}


node* mergesort(node *head)
{
	// Base case
	if(head==NULL || head->next==NULL)
	return head;
	
	// Recursive case
	
	//1. Mid point
	node *mid=midpoint(head);
	
	node *a=head;
	node *b=mid->next;
	mid->next=NULL;
	
	//2. Recursively sort
	a=mergesort(a);
	b=mergesort(b);
	
	
	//3. Merge the lists
	node *c=merge(a,b);
	
	return c;
	
	
}
void print(node *head)
{
	node *t;
	
	for(t=head;t;t=t->next)
	cout<<t->data<<" ";
	
	cout<<endl;
}


int main()
{
	node *head=NULL;
	buildlist(head);
	
	print(head);
	
	head=mergesort(head);
	cout<<"\n\nSorted Linked List \n";
	print(head);


	return 0;
}
