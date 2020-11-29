#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second

const int Nmax = 1000005;
int ngr[Nmax];
int nsm[Nmax];
int pgr[Nmax];
int psm[Nmax];    


////////////////////////////////////
void nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    
        stack<pair<int,int>> s;
        for(int i=n-1; i>=0; i--){
          //backward traversal
            while(!s.empty() && arr[i] > s.top().F){
                //pop all the elements to the right of the current element 
                //which are smaller than the current element
                //because they are not needed now as our current element 
                //is itself bigger than them

                s.pop();

            }
        //if the stack is empty there if no element to the right greater 
        //than the current element

            ngr[i] = s.empty() ? -1 : s.top().S;
            s.push({arr[i], i});
        }
}

void nextSmallerElement(vector<int>& arr) {
    int n = arr.size();
    
        stack<pair<int,int>> s;
        for(int i=n-1; i>=0; i--){
          //backward traversal
            while(!s.empty() && arr[i] < s.top().F){
                //pop all the elements to the right of the current element 
                //which are smaller than the current element
                //because they are not needed now as our current element 
                //is itself bigger than them

                s.pop();

            }
        //if the stack is empty there if no element to the right greater 
        //than the current element

            nsm[i] = s.empty() ? -1 : s.top().S;
            s.push({arr[i],i});
        }
}

void prevGreaterElement(vector<int>& arr) {
    int n = arr.size();
   
        stack<pair<int,int>> s;
        for(int i= 0; i < n; i++){
          //backward traversal
            while(!s.empty() && arr[i] > s.top().F){
                //pop all the elements to the right of the current element 
                //which are smaller than the current element
                //because they are not needed now as our current element 
                //is itself bigger than them

                s.pop();

            }
        //if the stack is empty there if no element to the right greater 
        //than the current element

            pgr[i] = s.empty() ? -1 : s.top().S;
            s.push({arr[i],i});
        }
}

void prevSmallerElement(vector<int>& arr) {
    int n = arr.size();
    stack<pair<int,int>> s;
        for(int i= 0 ; i< n; i++){
          //backward traversal
            while(!s.empty() && arr[i] < s.top().F){
                //pop all the elements to the right of the current element 
                //which are smaller than the current element
                //because they are not needed now as our current element 
                //is itself bigger than them

                s.pop();

            }
        //if the stack is empty there if no element to the right greater 
        //than the current element

            psm[i] = s.empty() ? -1 : s.top().S;
            s.push({arr[i],i});
        }
}