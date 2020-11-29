#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str){
    int l = 0; 
    int h = str.size() - 1; 
    while (h > l) 
    { 
        if (str[l++] != str[h--]) 
        { 
             
            return false; 
        } 
    } 
    return true; 
} 