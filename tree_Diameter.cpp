#include<bits/stdc++.h>
using namespace std;

vector<int> p; //parent vector
vector<vector<int>> g;// graph matrix


pair<int, int> dfs(int node, int par = -1, int dist = 0) {
	//this dfs function returns of pair p
	//given node = node in the argument
	// p.second = farthest node from given node in the tree
	// p.first = distance of that node from given node  

	p[node] = par; //used to find the final path
	pair<int, int> res = make_pair(dist, node);
	for (auto to : g[node]) {
		if (to == par) continue;
		res = max(res, dfs(to, node, dist + 1));
	}
	return res;
}

int main() {
	
	int n;
	cin >> n;
	p = vector<int>(n);
	g = vector<vector<int>>(n);
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].push_back(y);
		g[y].push_back(x);	
	}
	
			
	pair<int, int> da = dfs(0);// first dfs
	pair<int, int> db = dfs(da.second); // second dfs
	vector<int> diam;// vector containing the whole diameter
	int v = db.second;
	while (v != da.second) {
		diam.push_back(v);
		v = p[v];
	}
	diam.push_back(da.second);

}