vector<ll> primefactors;
void generatePrimeFactors(ll n)
{
  primefactors.clear();
  for(ll i=2;i*i<=n;i++)
  {
      if(n%i==0)
      {
          primefactors.pb(i);
          while(n%i==0)
              n=n/i;
      }
  }
  if(n!=1)
      primefactors.pb(n);
}