#include<iostream>
#include<map>
#include<list>


using namespace std;

template<typename t>
class graph
{
	map<t, list<t> > adlist;
	
	public:
			
		graph()
		{
			
		}
		
		void addedge(t u,t v,bool bidir=true)
		{
			adlist[u].push_back(v);
			
			if(bidir)
			adlist[v].push_back(u);
		}
		
		
		void print()
		{
			// Iterate over the map
			for(auto i:adlist)
			{
				cout<<i.first<<" --> ";
				
				// i.second is the list
				for(auto entry:i.second)
				{
					cout<<entry<<",";
				}
				
				cout<<endl;
			}
		}
};

int main()
{
	graph<string> g;
	
	g.addedge("Putin","Trump",false);
	g.addedge("Putin","Modi",false);
	g.addedge("Putin","Pope",false);
	g.addedge("Modi","Trump");
	g.addedge("Modi","Yogi");
	g.addedge("Yogi","Prabhu",false);
	g.addedge("Prabhu","Modi",false);
	
	g.print();
	
	return 0;
}
