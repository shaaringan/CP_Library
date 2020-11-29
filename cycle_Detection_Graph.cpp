#include<bits/stdc++.h>
using namespace std;



vector<int> adj[200001];
vector<int> vis(200001);
	
//Function to check whether a 
//graph contains cycle or not.
bool dfs(int node, int par){

vis[node] = 1;

for(int child : adj[node]){

	if(vis[child] == 0){
		//Check whether the child subtree
		//has a cycle.
		if(dfs(child, node) == true){
			return true;
		}
	}
	else{
		//if child if visited then check
		//whether this chid is parent, if not 
		// then cycle is present.
		if(child!= par){
			return true;
		}
	}

}	

// After running the for loop
// if no cycle is found return false.	
	return false;
}