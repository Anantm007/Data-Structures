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


void tailinsert(node *&head,int x)
{
	
	node *tail=head;
	
	while(tail->next!=NULL)
	{
		tail=tail->next;
	}
	
	tail->next=new node(x);
	return;
}


int len(node *head)
{
	int l=0;
	node *temp;
	
	for(temp=head;temp;temp=temp->next)
	l++;
	
	return l;
}


void middleinsert(node *&head,int pos,int x)
{
	if(pos==1 || head==NULL)	//	Start the linked list from here
	{
		head->data=x;
		head->next=NULL;
	}
	
	else if(pos>len(head))	// Insert at last
	{
		tailinsert(head,x);		
	}
	
	else		//	Insert at specific position
	{
		
		
		node *t=head;
		int i;
		
		for(i=1,t;i<pos-1;i++,t=t->next);
		
		node *y=new node(x);
		
		y->next=t->next;
		t->next=y;
		
	}
}





void print(node *head)
{
	node *temp;
	
	for(temp=head;temp;temp=temp->next)
	cout<<temp->data<<" ";
	
	cout<<endl;
}


int main()
{
	node *head=NULL;
	
	headinsert(head,10);
	headinsert(head,20);
	headinsert(head,30);
	
	middleinsert(head,2,40);
	middleinsert(head,4,50);
	middleinsert(head,10,100);
	
	tailinsert(head,64);
		
	print(head);
	
	return 0;		
}
