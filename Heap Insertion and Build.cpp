#include<bits/stdc++.h>

using namespace std;

class heap
{
	vector<int> v;
	
	// Configuration of heap (min. or max.)
	bool minheap;
	
	public:
	heap(bool type=true)
	{
		minheap=type;
		// Block the 0th index
		v.push_back(-1);
	}
	
	bool compare(int a,int b)
	{
		if(minheap)
		return a<b;
		
		else
		return a>b;
	}		
	
	void push(int data)
	{
		v.push_back(data);
		
		int index=v.size()-1;
		int parent=index/2;
		
		
		while(index>1 && compare(v[index],v[parent]))
		{
			swap(v[index],v[parent]);
			index=parent;
			parent/=2;
			
		}
	}
	
	bool isempty()
	{
		return v.size()==1;
	}
	
	int top()
	{
		return v[1];	
	}
	
			
};


int main()
{
	heap h1;
	
	h1.push(5);
	h1.push(15);
	h1.push(50);
	h1.push(20);
	h1.push(57);
	
	cout<<h1.top()<<endl;
	
	
	
	heap h2(false);
	
	h2.push(5);
	h2.push(15);
	h2.push(50);
	h2.push(20);
	h2.push(57);
	
	cout<<h2.top()<<endl;

}
