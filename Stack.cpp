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


class stack
{
	node *top;
	
	public:
		
		stack()
		{
			top=NULL;
		}
	
		void push(int d)
		{
			if(!top)
			{
				node *n=new node(d);
				top=n;
				return;
			}
			
			node *x=new node(d);
			x->next=top;
			top=x;	
					
		}
		
		void pop()
		{
			if(top->next==NULL)
			{
				top=NULL;
				return;
			}
			
			if(!top)
			return;
			
			node *t=top;
			top=top->next;
			delete t;
		}
		
		void print()
		{
			node *t;
			
			for(t=top;t;t=t->next)
			cout<<t->data<<" ";
			
			cout<<endl;
			
		}
};


int main()
{
	stack s;
	
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	
	s.print();
	
	s.pop();
	s.pop();
	s.pop();
	s.print();
	
	s.pop();
	s.pop();
	
	s.push(100);
	s.push(200);
	
	s.print();
	return 0;	
	
}
