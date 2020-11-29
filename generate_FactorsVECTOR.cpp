vector<ll> generateFactors(ll n)
{   vector<ll> factors;
    
    for(ll i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            factors.pb(i);
            if(n/i!=i)
                factors.pb(n/i);
        }
      }
   sort(factors.begin(),factors.end()); 
   return factors;
}  
