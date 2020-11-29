vector<int> tree[200001];
   

void dfs1(int nd = 1, int pr = 0){

    

    for(auto ch : tree[nd]){

        if(ch == pr)
            continue;

        dfs1(ch,nd);

        
    }
}