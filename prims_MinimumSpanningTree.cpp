#include<bits/stdc++.h>
using namespace std;
const int N = 1000005;

//Prim's algorithm which returns weight 
//of minimum spanning tree

//Also generates minimum spanning tree 

int n;
int dist[N], parent[N];
bool vis[N];
vector<pair<int, int> > g[N], tree[N];

int primsMST(int source) //Finds the cost and makes the MST
{
	for(int i=1;i<=n;i++){
		vis[i] = 0; 
		dist[i]=1e9;//initialising weight of all nodes except 0 to be infinity
	}
	
	set<pair<int, int> > s;
	//{distance, node};
	s.insert({0, source});
	int cost=0;
	dist[source]=0;
	while(!s.empty())
	{
		auto x = *(s.begin());
		s.erase(x);
		vis[x.second]=1;
		cost+=x.first; //adding this distance to total cost
		int u=x.second; // selected node
		int v=parent[x.second];
		int w=x.first; 
		//once we visit a node we dont't have to visit it again and also 
		//we visit the next nodes in increasing order of weights

		tree[u].push_back({v, w});
		tree[v].push_back({u, w});
		for(auto it:g[x.second])
		{
			if(vis[it.first])
				continue;
			if(dist[it.first] > it.second)
			{	
				s.erase({dist[it.first], it.first});
				dist[it.first]=it.second;
				s.insert({dist[it.first], it.first});
				parent[it.first]=x.second;
			}
		}
	}
	return cost;
}
