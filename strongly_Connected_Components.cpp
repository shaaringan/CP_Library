// Kosaraju's Algorithm for finding scc
#include<bits/stdc++.h>
using namespace std;
const int N = 2000005;



int n;
int grp = 0; // representing total number of different connected components
vector<int> g[N], rg[N], todo;
// g is graph, rg is reverse graph, todo will do the work of stack

int comp[N];
// comp[i] represents the component to which i belongs to
bool vis[N];


void dfs(int u)
{	// this is the first dfs to create the stack of 
	// elements according to their finishing time.
	vis[u] = 1;
	for(auto &it:g[u])
	{
		if(!vis[it])
			dfs(it);
	}
	todo.push_back(u);// pushing u in stack(vector)
}

void dfs2(int u, int val)
{	
	comp[u] = val;
	
	for(auto &it:rg[u])
	{
		if(comp[it] == -1)
			dfs2(it, val);
	}
}

void sccAddEdge(int from, int to)
{	

	// adds an edge in graph and reverse(transpose) graph

	g[from].push_back(to);
	rg[to].push_back(from);
}

void scc()
{
	for(int i = 1; i <= n; i++)
		comp[i] = -1;

	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
			dfs(i);
	}

	// we reverse todo so that it will become stack
	reverse(todo.begin(), todo.end());

	for(auto &it:todo)
	{
		if(comp[it] == -1)
			dfs2(it, ++grp);
	}

	
}