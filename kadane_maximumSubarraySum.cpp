ll maxSubArraySum(vector<ll> a) {
    ll ans=0, msf=0;
    for(ll b : a) {
        msf=max(msf+b, 0ll);
        ans=max(msf, ans);
    }
    return ans;
}
    