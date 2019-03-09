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
			left=NULL;
			right=NULL;
		}
};
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



bool search(node* root,int d)
{
	if(root==NULL)
	return false;
	
	if(root->data==d)
	return true;
	
	if(d <= root->data)
	search(root->left,d);
	
	if(d > root->data)
	search(root->right,d);
}

int main()
{
	node *root=build();
	int s;
	
	cout<<"\nEnter element to be searched  ";
	cin>>s;
	
	if(search(root,s))
	cout<<"Present";
	
	else
	cout<<"Not Present";
	
	return 0;
}

