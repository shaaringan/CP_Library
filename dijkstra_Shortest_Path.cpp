
//Dijkstra Algorithm for finding shortest path from node 1 to other nodes
#include<bits/stdc++.h>
using namespace std;
#define inf 200000000000

vector<vector<pair<int,long long>>> adj(100005);
vector<long long> dis(100005, inf);
vector<int> par(100005, -1);
// par[i] stores the parent of node i intially -1
int n;// number of nodes


void dijkshtra(){

    set<pair<long long,int>> s;
    s.insert({0,1}); 
    //start at any node doesn't matter

    // inserting first node int the set
    // dist = 0, node = 1
    dis[1] = 0; // distance of 1 from itself is 0

    while(!s.empty()){
        
        pair<long long,int> it = *(s.begin());

        s.erase(it);

        int node = it.second;
       	

        for(auto child : adj[node]){
            long long cd = child.second; //weight of choosen edge
            int cn = child.first;  //child node
            
            if(dis[cn] > dis[node] + cd){
                par[cn] = node; //setting the parent of child node as node
               
                if(dis[cn] != inf){
                	//we will have to erase the previously present entry  
                    s.erase({dis[cn], cn});
                }


                // this is updating dist[current node]
                // this can be modified for applying dijkstra to 
                // other cases    
                dis[cn] = dis[node] + cd;
                s.insert({dis[cn], cn});


            }

        }


    }

    // Following code is for printing the path from 1 to n;
    if(par[n] == -1){
    		// no path from 1 to n
            cout << -1 << endl;
        }

        else{
            vector<int> av;
            av.push_back(n);
            while(par[n]!= -1){
                n = par[n];
                av.push_back(n);
            }
            
            reverse(av.begin(), av.end());
            for(int i = 0; i< av.size(); i++){
                cout << av[i] << " ";
            }
        }


} 