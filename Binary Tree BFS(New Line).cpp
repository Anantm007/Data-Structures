#include<iostream>


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
			left=right=NULL;
		}	
	
};

// Pre Order Build
node* buildtree()
{
	int d;
	cin>>d;
	
	if(d==-1)
	return NULL;
	
	node *root=new node(d);
	root->left=buildtree();
	root->right=buildtree();
	
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
	node *root=buildtree();
	
	BFS(root);
	
	return 0;
}
