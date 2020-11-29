#include<bits/stdc++.h>
using namespace std;
int parent[200005];
int sze[200005];
int rnk[200005];

// additionally storing lists of elements in each set
vector<vector<int>> setlist(200005);
//merge two sets A and B ans concatenate the lists (in O(min(|A|,|B|)))
//This gives us O(nlogn): element can not change its set more than logn times, 
//because the change leads to (at least) doubling of the element's set size.

void merge(int a, int b){
    for(int i = 0; i < (setlist[b]).size(); i++){
        setlist[a].push_back(setlist[b][i]);
    }

    setlist[b].clear();
}



int find_set(int v) {
    //function to find representative of v;
    if (v != parent[v])
        parent[v] = find_set(parent[v]);
        
        return parent[v];
}
void union_sets(int a, int b) {
    //to merge the connected components of 
    //nodes a and b

    a = find_set(a);
    b = find_set(b);

    // a and b are group representatives, anything 
    // you want to do with the group do that 
    // with a or b;

    if (a != b) {
        if (sze[a] < sze[b])
            swap(a, b);

        merge(a, b);

        parent[b] = a;
        sze[a] += sze[b];
    }
    // union by rank
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);

        merge(a, b);

        parent[b] = a;
        if (rnk[a] == rnk[b])
            rnk[a]++;
    }

}



