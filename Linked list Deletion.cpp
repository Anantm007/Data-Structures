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


void headinsert(node *&head,int x)
{
	node *n= new node(x);
	
	n->next=head;
	head=n;
	
}

void deletehead(node *&head)
{
	if(head==NULL)
	return;
	
	
	node *t=head;
	
	head=head->next;	//	Second node becomes the first node
	
	delete t;
}

void deletetail(node *head)
{
	if(head==NULL)
	return;
	
	node *t=head;
	node *prev=NULL;
	
	while(t->next!=NULL)
	{
		prev=t;
		t=t->next;
	}
	
	delete t;
	prev->next=NULL;	//	Second last node now becomes last node	
	
}



void deletemiddle(node *head,int pos)
{
	if(pos==1)
	deletehead(head);
	
	if(head==NULL)
	return;
	
	node*t=head;
	node *prev=NULL;
	int i=1;
	
	while(i++<pos)
	{
		prev=t;
		t=t->next;
	}
	
	prev->next=t->next;
	delete t;
		
	
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
	
	headinsert(head,10);
	headinsert(head,20);
	headinsert(head,30);
	headinsert(head,40);
	headinsert(head,50);
	headinsert(head,60);
	headinsert(head,70);
	headinsert(head,80);
	
	print(head);
	
	deletehead(head);
	print(head);
	
	deletetail(head);
	print(head);
	
	deletemiddle(head,2);
	print(head);
	
	deletehead(head);
	print(head);
	
	
	
	deletemiddle(head,4);
	print(head);
	
	return 0;
}
