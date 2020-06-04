ll lis(vector<ll> a){
 ll n=a.size() ;
 deque<ll> d;
 rep(i,n){ //狭義はlower広義はupper
    ll p=lower_bound(d.begin(),d.end(),a[i])-d.begin();
    if(p==d.size()) d.push_back(a[i]) ;
    else d[p]=a[i] ;
 }
 return d.size() ;
}
