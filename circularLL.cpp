#include<iostream>
using namespace std;

class node
{
	public:
		
    string name;
    string branch;
    node* next;
    
    node(string n, string b)
    {
    	name=n;
    	branch=b;
    	next=NULL;
	}
};

void disp(node *head)
{
    if(head==NULL){
        cout<<"List Empty";
        return;
    }
 
    node *t = head;
     
    cout<<"\n "<<t->name<<" , "<<t->branch;
        t=t->next;
   
    while(t!=head)
	{
    	cout<<"\n"<<t->name<<" , "<<t->branch;
        t = t->next;
    }
	
}

void ins_begin(node *&head)
{
	string name, branch;
	
	cout<<"Enter name ";
    cin>>name;
    
    cout<<"Enter branch ";
    cin>>branch;
    
    node *x = new node(name, branch);
    
    if(head==NULL)
	{
        head = x;
        head->next = head;
        
		disp(head);
        return;
    }
    
    node*t=head;
    
	while(t->next!=t)
	    t=t->next;
    
    
	t->next=x;
    x->next=head;
    head=x;
    
    disp(head);
}

void del_end(node *&head)
{
	if(head==NULL)
	{
        cout<<"List Empty";
        return;
    }
    
    node *t = head;
    
    if(t->next==t)
	{
		cout<<"\nDeleted";
        head=NULL;
        
        disp(head);
        return;
    }
    
    
    while(t->next->next!=head)
	  	t=t->next;
    
	delete(t->next);
	t->next=head;   
	
	cout<<"\nDeleted";    
	disp(head);
}

int main()
{
	node *head = NULL;
    int n;
    
	while(1)
	{
    	
        cout<<"\nEnter 1 to insert at begin";
		cout<<"\nEnter 2 for deletion at end";
        cout<<"\nEnter 3 for traversal";
        cout<<"\nEnter 4 to exit	-	";
        cin>>n;
        
        switch(n)
        {
        
        case 1: ins_begin(head);
        	    break;
        	
        case 2: del_end(head);
        		break;
        		
        case 3: disp(head);
        		break;
        		
        case 4: exit(0);
        	
		}
	}
        
    return 0;
}
     
