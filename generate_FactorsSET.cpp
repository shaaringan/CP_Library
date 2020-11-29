set<ll> Divisors(ll n) 
{ 
    set<ll> ans;
    for (ll i=1; i<=sqrt(n); i++) 
    {
        if (n%i == 0) 
        {
            if (n/i == i) 
                ans.insert(i);
            else
            {
                ans.insert(i);
                ans.insert(n/i);
            }
        } 
    } 
    return ans;
}   
