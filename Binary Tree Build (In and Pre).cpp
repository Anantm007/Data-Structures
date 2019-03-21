#include<bits/stdc++.h>

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


node* create_from_Trav(int *in,int *pre,int s,int e)
{
	static int i=0;
	
	// Base Case
	if(s>e)
	return NULL;
	
	// Recursive Case
	node *root=new node(pre[i]);
	
	int index=-1;
	
	for(int j=s;s<=e;j++)
	{
		if(in[j] == pre[i])
		{
			index=j;
			break;
		}
	}
	
	i++;
	root->left = create_from_Trav(in,pre,s,index-1);
	root->right = create_from_Trav(in,pre,index+1,e);
	
	return root;
}


// Breadth First Search (BFS)
void BFS(node *root)
{
	queue<node*> q;
	
	q.push(root);
	
	while(!q.empty())
	{
		node *f=q.front();
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



int main()
{
	int in[] = {3,2,8,4,1,6,7,5};
	int pre[] = {1,2,3,4,8,5,6,7};
	
	int n=sizeof(in)/sizeof(int);
	
	node *root= create_from_Trav(in,pre,0,n-1);
	BFS(root);
	
	return 0;
}
