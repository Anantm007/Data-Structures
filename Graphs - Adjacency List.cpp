#include<iostream>
#include<list>

using namespace std;


class graph
{
	int v;
	list<int> *l;	//	List is a doubly linked list in c++ STL
	
	public:
		
		graph(int vertex)
		{
			v=vertex;
			l= new list<int>[v];		
		}
		
		void addEdge(int u, int v, bool bidir=true)
		{
			l[u].push_back(v);
			
			if(bidir)
			l[v].push_back(u);
		}
		
		
		void print()
		{
			for(int i=0;i<v;i++)
			{
				cout<<i<<" --> ";
				
				// l[i] is a linked list
				for(int vertex: l[i])
				cout<<vertex<<",";
				
				cout<<endl;
			}
			
			
		}
		
};



int main()
{
	// Graph has 5 vertices numbered from 0 to 4
	graph g(5);
	
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(4,3);
	g.addEdge(1,4);
	g.addEdge(1,2);
	g.addEdge(2,3);
	
	g.print();
	return 0;	
	
}
