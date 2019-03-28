#include<bits/stdc++.h>

using namespace std;

class heap
{
	public:
		
	vector<int> v;
	
	// Configuration of heap
	bool minheap;
	
	
	void heapify(int i)
	{
		int left=2*i;
		int right=2*i+1;
		
		// Assume curent is min
		int minindex=i;
		
		if(left<v.size() && compare(v[left],v[i]))
		{
			minindex=left;
		}
		
		if(right<v.size() && compare(v[right],v[minindex]))
		{
			minindex=right;
		}
		
		if(minindex!=i)
		{
		swap(v[i],v[minindex]);
		heapify(minindex);
		}
	
	}
	
	
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
	

	bool empty()
	{
		return v.size()==1;
	}
	
	
	int top()
	{
		return v[1];	
	}
	
	
	// Pop top element
	// Max element in case of max heap
	// Min element in case of min heap
	void pop()
	{
		int last=v.size()-1;
		
		swap(v[1],v[last]);
		v.pop_back();
		heapify(1);
	}
	
			
};


int main()
{
	heap h1(false);
	
	h1.push(5);
	h1.push(15);
	h1.push(50);
	h1.push(20);
	h1.push(57);
	
	
	while(!h1.empty())
	{
		cout<<h1.top()<<endl;
		h1.pop();	
	}
	
	
	return 0;
}
