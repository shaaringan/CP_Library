#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005

int n;
int a[MAXN];
int BIT[MAXN];

// reponsibility of index i = (i & -i)

//Whenever I perform a query I go to a particular
//index and go some index back until I reach zero.
//That back index is given by current 
//index - responsibility of cur index. 
	
//Sum(l,r) = Sum(1, r) - Sum(1, l-1);

void update(int cur_index, int val){
	//isme upar jaate hain current index se

	//O(logN)
	//Ek particular index khud ki responsiblity to hoga hi
	//saath ho aur index ki bhi reponsibility hoga uske upar
	//un saare index ko update krna padega

	for(; cur_index<=n; cur_index+=(cur_index&-cur_index)){
		BIT[cur_index] += val;
	}
}

void update_range(int a, int b, int v){  
//# Add v to a[a...b] 

  update(a, v);     
  update(b + 1, -v); 

}

long long query(int cur_index){
	//isme neeche aate hain

	//O(logN)
	long long sum = 0;

	for(;cur_index>0; cur_index-= (cur_index&-cur_index)){
		sum+= BIT[cur_index];
	}

	return sum;
}

int readSingle(int idx) {
  int sum = BIT[idx]; // this sum will be decreased
  if (idx > 0) { // the special case
    int z = idx - (idx & -idx);
    idx--; // idx is not important anymore, so instead y, you can use idx
    while (idx != z) { // at some iteration idx (y) will become z
      sum -= BIT[idx];
      // substruct BIT frequency which is between y and "the same path"
      idx -= (idx & -idx);
    }
  }
  return sum;
}

int main(){


	cin>>n;

	for(int i =1; i<= n; i++){
		//Contructing the intial BIT array
		cin>>a[i];
		update(i, a[i]);
	}

	int m;
	cin>>m;

	while(m--){
		// update 
		// When we want to update certain element.
		int x, value;
		update(x, value - a[x]);

		//sum from L to R
		int l,r;
		long long ans = query(r) - query(l-1);

	}
}