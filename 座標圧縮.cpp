vector<ll> ans(n) ; //圧縮後の配列
 vector<ll> za ;
 rep(i,n) za.pb(A[i]) ;
 sort(za.begin(),za.end()) ;
 za.erase(unique(za.begin(),za.end()),za.end()) ;
 rep(i,n) ans[i] = lower_bound(za.begin(),za.end(),A[i])-za.begin() ;
