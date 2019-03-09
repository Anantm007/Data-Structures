#include<iostream>
#include<queue>

using namespace std;

class node
{
	public:
		int data;
		node *left;
		node *right;
		
		node(int d)
		{
			data=d;
			left=NULL;
			right=NULL;
		}
};


bool BSTcheck(node *root, int min=INT_MIN, int max=INT_MAX) // INT_MIN is -infinity and INT_MAX is +infinity
{
	if(root==NULL)
	return true;
	
	if(root->data>min && root->data<max && BSTcheck(root->left,min,root->data) && BSTcheck(root->right,root->data,max))
	return true;
	
	return false;
	
}

// Accepts old root node and data. It returns new root node
node *insert_in_bst(node *root,int data)
{
	// Base Case
	if(root==NULL)
	{
		return new node(data);
	}
	
	// Recusive Case
	if(data<=root->data)
	{
		root->left = insert_in_bst(root->left,data);
	}
	
	
	if(data>root->data)
	{
		root->right = insert_in_bst(root->right,data);
	}
	
	return root;
}



node *build()
{
	// Continue reading numbers until -1 and add them to bst 
	// if number<=root then insert at left
	// if number>root then insert at right
	int d;
	cin>>d;
	
	node *root=NULL;
	
	while(d!=-1)
	{
		root = insert_in_bst(root,d);
		cin>>d;
	}
	
	return root;
}


// Breadth First Search (BFS)
void BFS(node *root)
{
	queue<node*> q;
	
	q.push(root);
	q.push(NULL);	//	To print each level on new line
		
	while(!q.empty())
	{
		node *f=q.front();
		if(f==NULL)
		{
			cout<<"\n";
			q.pop();
			
			if(!q.empty())
			q.push(NULL);
		}
		
		else
		{
			cout<<f->data<<" ";
			q.pop();
		
		if(f->left)
			{
				q.push(f->left);
			}
		
		if(f->right)
			{
				q.push(f->right);
			}
		
		}
		
	}
}


int main()
{
	node *root=build();
	
	cout<<endl;
	BFS(root);
	
	if(BSTcheck(root))
	cout<<"\nYes";
	
	else
	cout<<"\nNo";
	
	return 0;
}
