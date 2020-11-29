#define ll long long int
const  ll MODA = 1000000007;
ll   fact[100005]={};            // used by generateFactorial() & ncr()
    
    ll   modi (ll a){ 
    	ll m=MODA,s=1,p=0;  
    	while(a>1){  
    		ll q=a/m,t=m;  m=a%m; a=t; t=p; p=s-q*p; s=t;
    	} 
    	return s>=0 ? s :s+MODA; 
    	}
  
    ll   ncr(ll n, ll r){ 
    
    	if(r==0)return 1;  
    	fact[0]=1; for(int i=1 ; i<=n; i++) fact[i] = fact[i-1]*i%MODA;   
    	return (fact[n]* modi(fact[r]) % MODA *  modi(fact[n-r]) % MODA) % MODA; 

    }