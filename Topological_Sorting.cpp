#include<bits/stdc++.h>
using namespace std;

///////////////////////////////////
    
vector<int> adj[10001];
int indegree[10001];
vector<int> res;
////////////////////////////////////

//Kahn's Algorithm for topological sorting

bool kahn(int n){

    // we use priority queue so that after sorting
    // we get the lexicographically minimal order 
    priority_queue <int, vector<int>, greater<int>> pq;


    //we push those nodes having outdegree as 0 to 
    // the priority queue

    for(int i =1; i<=n; i++){
        if(indegree[i] == 0){
            pq.push(i);
        }
    }
    
    while(!pq.empty()){
        res.pb(pq.top());

        int curnode = pq.top();
        pq.pop();

        // Iterate through all its 
        // neighbouring nodes 
        // of curnode and 
        // decrease their in-degree 
        // by 1
        for(int x:adj[curnode]){

            indegree[x]--;
            // If in-degree becomes zero, 
            // add it to queue 
            if(indegree[x] == 0){
                pq.push(x);
            }

        }

    }

    // if(res.size() != n) that implies that cycle
    // exist in the graph

    //else the topological sort order is available in the 
    // res vector/
    return res.size() == n;

}
/////////////////////////////////////////////////////////////
///Type2:- 
///make adj of size n==number of nodes
vector<int> topoSortBFS(vector<vector<int>> adj)
{
    int i,n=adj.size();
    vector<int> inDeg(n,0);
    queue<int> q;
    vector<int> order;
    for(i=0;i<n;i++)
    {
        for(auto it:adj[i])
            inDeg[it]++;
    }
    for(i=0;i<n;i++)
    {
        if(!inDeg[i])
            q.push(i);
    }
    while(!q.empty())
    {
        int u=q.front();q.pop();
        order.pb(u);
        for(auto v:adj[u])
        {
            inDeg[v]--;
            if(inDeg[v]==0)
            q.push(v);
        }
    }
    return order;
}