#include<iostream>

using namespace std;


// Class node (templated)
template<typename t>

class node
{
	public:
		
		string key;
		t value;
		node<t> *next;
		
		node(string key,t v)
		{
			this->key=key;	// OR key=k, if k was passed as a parameter
			value=v;
		}
		
		~node()
		{
			if(next!=NULL)
			delete next;
		}
};



// Hash Table class (templated)
template<typename t>
class HashTable
{
	int cs;	  // Current array size	
	int ts;  // Max array size
	node<t> **buckets;	//	Pointer to array of pointers
	
	void rehash()
	{
		node<t> **oldbuckets=buckets;
		int old=ts;
		ts*=2;
		
		cs=0;
		
		buckets= new node<t>* [ts];
		for(int i=0;i<ts;i++)
		buckets[i]=NULL;
		
		// Read elements from old tale and insert them 
		for(int i=0;i<old;i++)
		{
			node<t>*temp= oldbuckets[i];
			
			if(temp!=NULL)
			{	
				while(temp!=NULL)
				{
					insert(temp->key,temp->value);
					temp=temp->next;
				}
				
				// Delete the old bucket i 
				delete oldbuckets[i];  		//	Will make call to destructor
			}
		}
		
		delete []oldbuckets;	// Free old memeory
	}
	
	// HashFunction to convert key into int
	int HashFn(string key)
	{
		int ans=0;
		int l=key.length();
		int p=1;	// 37^0=1
		
		for(int i=0;i<l;i++)
		{
			ans+=key[l-i-1]*p;
			
			p*=37;
			p%=ts;
			ans%=ts;
		}
		
		return ans;
	}
	
	public:
		
		// Constructor
		HashTable(int ds=7)
		{
			cs=0;
			ts=ds;
			buckets=new node<t>*[ts];
			
			// Make all addresses as NULL
			for(int i=0;i<ts;i++)
			buckets[i]=NULL;
		}
		
		
		
		// Insert the elements into the hash map
		void insert(string key,t value)
		{
			int i=HashFn(key);
			
			node<t> *n = new node<t>(key,value);
			n->next=buckets[i];
			buckets[i]=n;
			
			cs++;
			
			// Load factor to rehash
			float load_factor= (float) cs/ts;
			
			if(load_factor>.7)
			{
				cout<<"Load factor is "<<load_factor<<endl;
				rehash();
			}
			
		}
		
		
		// Print
		void print()
		{
			// iterate over buckets array
			for(int i=0;i<ts;i++)
			{
				node<t> *temp=buckets[i];
				cout<<"bucket "<<i<<" ->";
				
				while(temp!=NULL)
				{
					cout<<temp->key<<" || ";
					temp=temp->next;
				}
				
				cout<<endl;
			}
		}
		
		// Function to search an element through a key and return its address. It returns NULL if key is not found
		t* search(string key)
		{
			int i=HashFn(key);
			
			node<t> *temp=buckets[i];
			
			while(temp!=NULL)
			{
				if(temp->key==key)
				return &(temp->value);
				
				temp=temp->next;
			}
			
			return NULL;	
		}
				
		// Delete an element from hash table
		t* erase(string key)
		{
			
		}
		
		
		t& operator[] (string key)
		{
			t* temp=search(key);
			
			if(temp==NULL)
			{
				// Insertion
				t garbage;
				insert(key,garbage);
				
				t* value = search(key);
				return *(value);
			}
		}
		
		
		
				
};


int main()
{
	
	// Creating a Hash table of size 7
	HashTable<int> h(7);
	
	// Inserting elements into the hash table
	h.insert("Mango",100);
	h.insert("Apple",170);
	h.insert("Banana",140);
	h.insert("Guava",130);
	h.insert("Chiku",120);
	
	// Printing the hash table
	h.print();
	
	// Searching a value through key
	/*string f;
	cin>>f;
	
	int *price=h.search(f);
	
	if(price==NULL)
	cout<<"Not found"<<endl;
		
	else
	cout<<"price	=	"<<*price<<endl;
	*/
	
	return 0;
}
