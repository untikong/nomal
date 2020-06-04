ll lds(vector<ll> a){
 ll n=a.size() ;
 deque<ll> d;
 rep(i,n){  //広義はlower 狭義はupper
    ll p=lower_bound(d.begin(),d.end(),a[i])-d.begin(); 
    if(p==0) d.push_front(a[i]) ;
    else d[p-1]=a[i] ;
 }
 return d.size() ;
}
