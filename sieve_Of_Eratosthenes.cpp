const ll N=1e7+2;
bool prime[105];                            // used by SieveOfEratosthenes()
void SieveOfEratosthenes(ll n)             //O(nloglogn)
{
    memset(prime, true, sizeof(prime));
 
    for (ll p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (ll i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
}


vector<int> SieveOfEratosthenes(int n) 
{ 
  
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        
        if (prime[p] == true) 
        {  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    vector<int> v;
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          v.pb(p);
} 