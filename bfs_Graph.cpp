vector<int> adj[200001];
int n;
 
void bfs(int src)
{
	queue<int> q;
	vector<bool> used(n + 1);

 
	q.push(src);
	used[src] = true;
 
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		for (int u : adj[v])
		{
			if (!used[u])
			{
				used[u] = true;
				q.push(u);
				

			}
		}
	}
 
	
}