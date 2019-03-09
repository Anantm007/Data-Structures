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


node *buildtree()
{
	// Base Case
	int d;
	cin>>d;
	
	if(d==-1)
	return NULL;
	
	// Recursive Case
	node *root=new node(d);
	root->left=buildtree();
	root->right=buildtree();
	return root;
	
}

void print(node *root)
{
	if(root==NULL)
	return;
	
	// Print the root followed by children
	cout<<root->data<<" ";
	print(root->left);
	print(root->right);
}

int main()
{
	node *root=buildtree();
	
	print(root);
	
	return 0;
}
