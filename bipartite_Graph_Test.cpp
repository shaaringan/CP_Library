vector<int> adj[200001];
vector<int> vis(200001);
//color is either 0 or 1
vector<int> color(200001);
	
bool dfs(int v, int c){


	vis[v] = 1;
	color[v] = c;

	for(int child : adj[v]){


		if(vis[child] == 0){

			// c^1 is XOR. If c==0 then c^1==1 and 
			// ifc == 1 then c^1 == 0
			if(dfs(child, c^1) == false){
				return false;
			}

			else{
				// checking whether child and parent 
				// are colored in different colors or not.
				if(color[v] == color[child]){
					return false;
				}
			}
		}



	}
	// after running the for loop
	// return true
	return true;

}