// CPP code for printing shortest path between 
// two vertices of unweighted graph 
#include <bits/stdc++.h> 
using namespace std; 
vector<int> adj[200005];

// predecessor[i] array stores predecessor of 
// i and distance array stores distance of i 
// from source

int pred[200005];
int dist[200005]; 

// a modified version of BFS that stores predecessor 
// of each vertex in array p 
// and its distance from source in array d 
bool BFS(int src, int dest, int v) 
{ 

    list<int> queue; 
    bool visited[v]; 
    for (int i = 0; i < v; i++) { 
        visited[i] = false; 
        dist[i] = INT_MAX; 
        pred[i] = -1; 
    } 
  
    // now source is first to be visited and 
    // distance from source to itself should be 0 
    visited[src] = true; 
    dist[src] = 0; 
    queue.push_back(src); 
  
    // standard BFS algorithm 
    while (!queue.empty()) { 
        int u = queue.front(); 
        queue.pop_front(); 
        for (int i = 0; i < adj[u].size(); i++) { 
            if (visited[adj[u][i]] == false) { 
                visited[adj[u][i]] = true; 
                dist[adj[u][i]] = dist[u] + 1; 
                pred[adj[u][i]] = u; 
                queue.push_back(adj[u][i]); 
  
                // We stop BFS when we find 
                // destination. 
                if (adj[u][i] == dest) 
                    return true; 
            } 
        } 
    } 
  
    return false; 
} 
  
// utility function to print the shortest distance 
// between source vertex and destination vertex 
void printShortestDistance(int s, 
                           int dest, int v) 
{ 
     
    
  
    if (BFS(s, dest, v) == false) { 
        return; 
    } 
  
    // vector path stores the shortest path 
    vector<int> path; 
    int crawl = dest; 
    path.push_back(crawl); 
    while (pred[crawl] != -1) { 
        path.push_back(pred[crawl]); 
        crawl = pred[crawl]; 
    } 
  
    // distance from source is in distance array 
    cout << "Shortest path length is : "
         << dist[dest]; 
  
    // printing path from source to destination 
    cout << "\nPath is::\n"; 
    for (int i = path.size() - 1; i >= 0; i--) 
        cout << path[i] << " "; 
} 
  
// Driver program to test above functions 
int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
      ios_base::sync_with_stdio(false); cin.tie(0);
 

    int n,m;
    cin >> n >> m;
    
    for(int i =1; i<=m; i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }    

   

    printShortestDistance(0, 6, n); 
   
} 