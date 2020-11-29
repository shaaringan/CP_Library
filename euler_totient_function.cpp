
//returns number of 
//positive integers upto n which are coprime with n

ll Phi(ll m){
	ll ans=m;
	for(ll i=2;i*i<=m;i++){
		if(m%i==0){
			ans-=ans/i;
			while(m%i==0) m/=i;
		}
	}
	if(m>1) ans-=ans/m;
	return ans;
}