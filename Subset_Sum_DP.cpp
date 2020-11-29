#include<bits/stdc++.h>
using namespace std;
//Approach1
// Subset Sum
// TC:- O(N*SUM)
// SC:- O(SUM)
bool is_subset_sum(vector<int>& v,int sum)
{
int n=v.size();
vector<int>dp(sum+1,0);
dp[0]=1; //sum =0 is always attainable.


//We choose element one by one
for(int i=0;i<n;i++)

	// We go from right to left
	for(int j=sum;j>=v[i];j--)
     dp[j]|=dp[j-v[i]];

return dp[sum];

}


//Approach2
// Subset Sum
// TC:- O(N*SUM)
// SC:- O(N*SUM)
bool isSubsetSum(int set[], int n, int sum) 
{ 
    // The value of subset[i][j] will be true if 
    // there is a subset of set[0..j-1] with sum 
    // equal to i 
    bool subset[n + 1][sum + 1]; 
  
    // If sum is 0, then answer is true
    // We can take 0 elements and that will amount to 0 
    for (int i = 0; i <= n; i++) 
        subset[i][0] = true; 
  
    // If sum is not 0 and set is empty, 
    // then answer is false 
    for (int i = 1; i <= sum; i++) 
        subset[0][i] = false; 
  
    // Fill the subset table in botton up manner 
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= sum; j++) { 
            if (j < set[i - 1]) 
            	//Current element is greater than required sum i.e j
                subset[i][j] = subset[i - 1][j]; 
            if (j >= set[i - 1]) 
            	//Current element is smaller than or equal to required sum i.e j
                subset[i][j] = subset[i - 1][j] 
                               || subset[i - 1][j - set[i - 1]]; 
        } 
    } 
       return subset[n][sum]; 
} 
  