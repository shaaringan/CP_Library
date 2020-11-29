
#include<bits/stdc++.h>
using namespace std;

//O(LOGN)
// value just smaller than or equal to target 
// in vector arr

// returns -1 if not found

// can be easily modified to return the index
// of that value

// can also be easily modifies to return value
// just smaller than target in vector arr


int nexts(vector<int> &arr, int target)  
{   int end = arr.size()-1;
    int start = 0;  
  
    int ans = -1;  
    while (start <= end)  
    {  
        int mid = (start + end) / 2;  
  
        // Move to the left side if the target is smaller  
        if (arr[mid] > target)  
        {  
            end = mid - 1;  
        }  
  
        // Move right side  
        else 
        {  
            ans = mid;  
            start = mid + 1;  
        }  
    }  
    if(ans != -1){
    return arr[ans];
    }
    else{
        return -1;
    }  
}  