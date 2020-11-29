#include<bits/stdc++.h>
using namespace std;

int n, m;
bool vis[1001][1001];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool isValid(int x, int y){


    if(x < 0 || x >= n || y < 0 || y >= m)
        return false;

    if(vis[x][y] == true)
        return false;

    return true;

}


void dfs(int x, int y){
    vis[x][y] = 1;

    for(int i =0; i< 4; i++){
        if(isValid(x+dx[i], y+dy[i]))
           dfs(x+dx[i], y+dy[i]);
    }



}

    