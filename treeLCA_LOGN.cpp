#include <bits/stdc++.h>
using namespace std;


#define MAXN 200001 
#define level 20

vector <int> tree[MAXN]; 
int depth[MAXN]; 
int parent[MAXN][level]; 
  
// pre-compute the depth for each node and their 
// first parent(2^0th parent) 
// time complexity : O(n) 
void dfs(int cur, int prev) 
{ 
    depth[cur] = depth[prev] + 1; 
    parent[cur][0] = prev; 
    for (int i=0; i<tree[cur].size(); i++) 
    { 
        if (tree[cur][i] != prev) 
            dfs(tree[cur][i], cur); 
    } 
} 
  
// Dynamic Programming Sparse Matrix Approach 
// populating 2^i parent for each node 
// Time complexity : O(nlogn) 
void precomputeSparseMatrix(int n) 
{ 
    for (int i=1; i<level; i++) 
    { 
        for (int node = 1; node <= n; node++) 
        { 
            if (parent[node][i-1] != -1) 
                parent[node][i] = 
                    parent[parent[node][i-1]][i-1]; 
        } 
    } 
} 
  
// Returning the LCA of u and v 
// Time complexity : O(log n) 
int lca(int u, int v) 
{ 
    if (depth[v] < depth[u]) 
        swap(u, v); 
  
    int diff = depth[v] - depth[u]; 
  
    // Step 1 of the pseudocode 
    for (int i=0; i<level; i++) 
        if ((diff>>i)&1) 
            v = parent[v][i]; 
  
    // now depth[u] == depth[v] 
    if (u == v) 
        return u; 
  
    // Step 2 of the pseudocode 
    for (int i=level-1; i>=0; i--) 
        if (parent[u][i] != parent[v][i]) 
        { 
            u = parent[u][i]; 
            v = parent[v][i]; 
        } 
  
    return parent[u][0]; 
} 
  
void addEdge(int u,int v) 
{ 
    tree[u].push_back(v); 
    tree[v].push_back(u); 
} 

int parentofV(int v,int h)

{

    for (int i=0;i<level;i++) 
        if (h&(1<<i)) v=parent[v][i]; return v;
}    

void solve() 
{ 

    memset(parent,-1,sizeof(parent));
    memset(tree,0,sizeof(tree));
    int n;
    cin >> n; 
    

    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        addEdge(u,v);
        // trace(u,v);
    }

    depth[0] = -1;
    dfs(1,0); 
    precomputeSparseMatrix(n);    

}