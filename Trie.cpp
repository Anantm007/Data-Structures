#include<bits/stdc++.h>

using namespace std;

#define hashmap unordered_map <char,node *>

class node
{
	public:
		char data;
		hashmap h;
		bool terminal;
		
		node(char d)
		{
			data=d;
			terminal=NULL;	
			// Hashmap is already empty
		}	
};


class trie
{
	node* root;
	
	public:
		
		trie()
		{
			root = new node('\0');
		}
		
		
		// Insertion
		void insert(char *word)
		{
			node *temp = root;
			
			for(int i=0;word[i]!='\0';i++)
			{
				char ch = word[i];
				
				if(temp->h.count(ch)==0)
				{
					node *child = new node(ch);
					temp->h[ch] = child;
					temp = child;
				}
				
				else
				temp = temp->h[ch];
			}
			
			temp->terminal = true;
		}
		
		// Lookup
		bool search(char *word)
		{
			node *temp = root;
			
			for(int i=0;word[i]!='\0';i++)
			{
				char ch = word[i];
				
				if(temp->h.count(ch))
				temp = temp->h[ch];
				
				else
				return false;
				
			}
			
			return temp->terminal;
		}
		
};

int  main()
{
	char word[10][100] = {"apple", "ape", "coder", "coding", "no"};
	
	trie t;
	
	for(int i=0;i<5;i++)
	t.insert(word[i]);
	
	char searchword[100];
	cin.getline(searchword,100);
	
	if(t.search(searchword))
	cout<<"found"<<endl;
	
	else
	cout<<"not found"<<endl;
	
	return 0;
}
