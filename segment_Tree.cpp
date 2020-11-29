#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
int n, t[4*MAXN];
vector<int> inpa;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = inpa[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

// current vertex == v
// current segment == (tl and tr) 
// boundaries of the query ==  (l and r)


int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);

}


void point_Update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            point_Update(v*2, tl, tm, pos, new_val);
        else
            point_Update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}