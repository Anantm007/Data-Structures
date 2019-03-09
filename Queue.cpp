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

class queue
{
	node *f;
	node *r;
	
	public:
		queue()
		{
			f=r=NULL;
		}
		
		void push(int d)
		{
			if(f==NULL)
			{
				node *n=new node(d);
				f=r=n;
				return;
			}
			
			node *t=new node(d);
			r->next=t;
			r=t;
		}
		
		void pop()
		{
			if(f==r)
			{
				f=r=NULL;
				return;
			}
			node *t=f;
			
			f=f->next;
			delete t;
			
		}
		
		void print()
		{
			node *t;
			
			for(t=f;t;t=t->next)
			cout<<t->data<<" ";
			
			cout<<endl;
		}
		
		
};

int main()
{
	queue q;
	
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	
	q.print();
	
	q.pop();
	q.pop();
	q.pop();
	q.print();
	
	q.pop();
	q.pop();	
	
	q.print();
	
	q.push(200);
	q.print();
	
	return 0;
	
}
