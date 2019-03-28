#include<bits/stdc++.h>

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
		
		
		void bfs(t source)
		{
			queue<t> q;
			
			map<t,bool> visited;
			q.push(source);
			
			visited[source] = true;
			
			while(!q.empty())
			{
				t node = q.front();
				cout<<node<<" ";
				
				q.pop();
				
				// For neighbours of current node, find out nodes which are not yet visited
				for(int neighbour : adlist[node])
				{
					if(!visited[neighbour])
					{
						q.push(neighbour);
						visited[neighbour]=true;
					}
				}
			}
		}
};

int main()
{
	graph<int> g;
	
	g.addedge(0,1);
	g.addedge(1,2);
	g.addedge(0,4);
	g.addedge(2,4);
	g.addedge(2,3);
	g.addedge(3,5);
	g.addedge(3,4);
	
	g.bfs(0);
	
	return 0;
}
