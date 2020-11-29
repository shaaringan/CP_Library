#include<bits/stdc++.h>
using namespace std;


//O(LOGN)
// value just greater than or equal to target 
// in vector arr

// returns -1 if not found

// can be easily modified to return the index
// of that value

// can also be easily modifies to return value
// just greater than target in vector arr





int nextg(vector<int> &arr, int target)

{ 
    int start = 0; 
    int end = arr.size()-1;
    int ans = -1; 
    while (start <= end) 
    { 
        int mid = (start + end) / 2; 
  
        // Move to right side if target is 
        // greater. 
        if (arr[mid] < target) 
            start = mid + 1; 
  
        // Move left side. 
        else
        { 
            ans = mid; 
            end = mid - 1; 
        } 
    } 
    if(ans != -1){
    return arr[ans];
    }
    else{
        return -1;
    } 
} 