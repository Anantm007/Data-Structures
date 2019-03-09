// incomplete

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


void inserttail(node *&head,int d)
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
	inserttail(head,1);
	inserttail(head,2);
	inserttail(head,3);
	inserttail(head,4);
	inserttail(head,5);
	inserttail(head,2);
	inserttail(head,3);
}


bool detect(node *head)
{
	node *slow = head;
	node *fast = head;
	
	while(fast!=NULL && fast->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
		
		if(fast->data==slow->data)
		return true;
	}
	
	return false;
}

node *floydremoval(node *head)
{
	node *slow = head;
	node *fast = head;
	
	while(fast!=NULL && fast->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
		
		if(fast->data==slow->data)
		{
			fast=slow;
			slow=head;
			
			
			while(1)
			{
				slow=slow->next;
				fast=fast->next;
				
				if(slow->data==fast->next->data)
				{
					fast->next=NULL;
					return head;
				}
				
			}
		}
	}	
	return head;
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
	
	if(detect(head))
	{
		cout<<"cycle";
		head=floydremoval(head);
		print(head);
		return 0;
	}
	
	print(head);
	
	return 0;
}


