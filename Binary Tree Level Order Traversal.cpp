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


// UDF to find height of the tree
int height(node *root)
{
	if(root==NULL)
	return 0;
	
	int ls=height(root->left);
	int rs=height(root->right);
	
	return max(ls,rs)+1;
}


void printLevel(node *root,int k)
{
	if(root==NULL)
	return;
	
	if(k==1)
	{
		cout<<root->data<<" ";
		return;
	}
	
	printLevel(root->left,k-1);
	printLevel(root->right,k-1);
}

void printAll(node *root)
{
	int h=height(root);
	
	for(int i=1;i<=h;i++)
	{
		printLevel(root,i);
		cout<<endl;
	}
		
}
int main()
{
	node *root=buildtree();
	
	printAll(root);
	
	return 0;
}
