
#include<bits/stdc++.h>
using namespace std;

int n, m;
bool vis[1001][1001];
int dis[1001][1001];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool isValid(int x, int y){


    if(x < 0 || x >= n || y < 0 || y >= m)
        return false;

    if(vis[x][y] == true)
        return false;

    return true;

}

void bfs(int srcx, int srcy){

	queue<pair<int,int>> q;
	q.push({srcx, srcy});
	dis[srcx][srcy] = 0;
	vis[srcx][srcy] = 1;

	while(!q.empty()){
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();

		for(int i = 0; i< 4; i++){
			if(isValid(curx+dx[i], cury+dy[i])){
				int newx  = curx + dx[i];
				int newy = cury + dy[i];

				dis[newx][newy] = 1 + dis[curx][cury];
				vis[newx][newy] = 1;
				q.push({newx, newy});
			}
		}
	}

}