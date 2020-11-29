//triedodin
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 1000001; 

//Time Complexity: O(10^6) for precomputing 
//and O(1) for every query.
  
// array to store inverse of 1 to N 
ll factorialNumInverse[N + 1]; 
  
// array to precompute inverse of 1! to N! 
ll naturalNumInverse[N + 1]; 
  
// array to store factorial of first N numbers 
ll facto[N + 1]; 
    
void InverseofNumber(ll p) 
{ 
    naturalNumInverse[0] = naturalNumInverse[1] = 1; 
    for (int i = 2; i <= N; i++) 
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p; 
} 
// Function to precompute inverse of factorials 
void InverseofFactorial(ll p) 
{ 
    factorialNumInverse[0] = factorialNumInverse[1] = 1; 
  
    // precompute inverse of natural numbers 
    for (int i = 2; i <= N; i++) 
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p; 
} 
  
// Function to calculate factorial of 1 to N 
void factorial(ll p) 
{ 
    facto[0] = 1; 
  
    // precompute factorials 
    for (int i = 1; i <= N; i++) { 
        facto[i] = (facto[i - 1] * i) % p; 
    } 
} 
  
// Function to return nCr % p in O(1) time 
ll Binomial(ll N, ll R, ll p) 
{    if(R < 0 || R > N){
        return 0;
    }  
    // n C r = n!*inverse(r!)*inverse((n-r)!) 
    ll ans = ((facto[N] * factorialNumInverse[R]) 
              % p * factorialNumInverse[N - R]) 
             % p; 
    return ans; 
}

void solve(){

    ll p = 1000000007; 
    InverseofNumber(p); 
    InverseofFactorial(p); 
    factorial(p); 

    ll n, m;

    cin >> n >> m;

    
    ll ans = Binomial(m,n,p);//Calculates mCn%p

    

    cout << ans << endl;

}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
        ios_base::sync_with_stdio(false); cin.tie(0);
     

        int t= 1;
        //cin >> t;

        while(t--){
            solve();
        }

    

  }