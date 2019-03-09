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


void insertattail(node *&head,int d)
{
	
	if(head==NULL)
	{
		node *n=new node(d);
		head=n;
		return;
	}
	
	node *t=head;
	
	while(t->next!=NULL)
	t=t->next;
	
	t->next=new node(d);
	return;
}


void buildlist(node *&head)
{
	int d;
	char ch;
	
	do
	{
		cout<<"\nEnter the value	-	";
		cin>>d;
		
		insertattail(head,d);
		
		cout<<"Enter more   ?  ";
		cin>>ch;
		
	}while(ch=='y' || ch=='Y');
}



void print(node *head)
{
	node *t;
	
	for(t=head;t;t=t->next)
	cout<<t->data<<" ";
	
}


void reverse(node *&head)
{
	node *c=head;	//	current
	node *p=NULL;	//	previous
	node *n;		//	next node
	
	while(c!=NULL)
	{
		// save the next node
		n=c->next;
		
		// make current node point to prev. node
		c->next=p;
		
		// update previous and current
		p=c;
		c=n;
	}
	
	head=p;
}

int main()
{
	node *head=NULL;
	
	buildlist(head);
	
	cout<<"Original Linked list \n";
	print(head);
	
	reverse(head);
	
	cout<<"\nReversed Linked list \n";
	print(head);
	
	return 0;
}
