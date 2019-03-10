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


// It works only on a sorted array
node *insert(int ar[],int s, int e)
{
	if(s>e)
	return NULL;
	
	int m=(s+e)/2;
	
	node* root=new node(ar[m]);
	
	root->left=insert(ar,s,m-1);
	root->right=insert(ar,m+1,e);
	
	return root;
}

void pre(node* root) 
{ 
    if (root == NULL) 
        return; 
    
	cout<<root->data<<" "; 
    pre(root->left); 
    pre(root->right); 
} 



void print(node* root, int k1, int k2) 
{ 
   if (root==NULL) 
      return; 
  
   if ( k1 > root->data ) 
     print(root->right, k1, k2); 
  
   if ( k1 <= root->data && k2 >= root->data ) 
      cout<<root->data<<" "; 
  
   if ( k2 < root->data ) 
     print(root->left, k1, k2); 
} 



int main()
{

    int t;
    cin>>t;
    int a,b;
    
    while(t--)
    {
      int n,ar[10000],i;
      
      cin>>n;
      for(i=0;i<n;i++)
      cin>>ar[i];
      
      cin>>a>>b;
      sort(ar,ar+n);
      
      node* root=insert(ar, 0, n-1); 
      pre(root);  
      cout<<endl;
      print(root,a,b);
      cout<<endl;
      
    }
    
    return 0;
}


