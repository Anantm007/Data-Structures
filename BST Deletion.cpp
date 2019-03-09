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



node* deleteInBST(node*root,int data)
{	
    if(root==NULL)
        return NULL;
        
    else if(data<root->data)
	{
        root->left = deleteInBST(root->left,data);
        return root; 
    }
    
    else if(data==root->data){
        //Found the node to delete 
        // There will be 3 cases
        
        
        //1. Node with 0 children (Leaf)
        if(root->left==NULL && root->right==NULL)
		{
            delete root;
            return NULL;
        }
        
        //2. node with only 1 child
            if(root->left!=NULL && root->right==NULL)
			{
                node* temp = root->left;
                delete root;
                return temp;
            }
            
            if(root->right!=NULL && root->left==NULL)
			{
                node* temp = root->right;
                delete root;
                return temp;
            }
            
        //3. Node with 2 children
            node *replace = root->right;
            
			//Finding the inorder successor from right subtree
            while(replace->left!=NULL)
			{
                replace = replace->left;
            }
            root->data = replace->data;
            root->right = deleteInBST(root->right,replace->data);
            
			return root;
    }
    
    
    else
	{
        root->right = deleteInBST(root->right,data);
        return root;
    }
    
    
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

	int d;
	cout<<"\nEnter element to be deleted	-	";
	cin>>d;
	
	root=deleteInBST(root,d);
	cout<<endl;
	BFS(root);

	return 0;
}
