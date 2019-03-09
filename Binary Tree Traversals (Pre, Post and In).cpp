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


// Inorder Traversal
void printIn(node *root)
{
	if(root==NULL)
	return;
	
	// Print left root right
	printIn(root->left);
	cout<<root->data<<" ";
	printIn(root->right);
}


// Preorder traversal
void printPre(node *root)
{
	if(root==NULL)
	return;
	
	// Print Root left right
	cout<<root->data<<" ";
	printPre(root->left);
	printPre(root->right);
}



// Post Order Traversal
void printPost(node *root)
{
	if(root==NULL)
	return;
	
	// Print Left right root
	printPost(root->left);
	printPost(root->right);
	cout<<root->data<<" ";
}

int main()
{
	node *root=buildtree();
	
	printIn(root);
	cout<<endl;
	
	printPre(root);
	cout<<endl;
	
	printPost(root);
	cout<<endl;
		
	return 0;
}
