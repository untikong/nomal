// num[i]^num[j]が最大になるようなi,jについて
//{num[i]^num[j],{i,i}}を返す
//mビット目を見ている
pair<ll,P>  dfs(vector<ll> A,vector<ll> B,ll m,vector<vector<ll>>&V,vector<ll> &num){
    ll x=A.size(); ll y=B.size();
    if(x*y==0) return{-1,{0,0}};
    if(m==-1){
      return {num[A[0]]^num[B[0]],{A[0],B[0]}};
    }

    vector<ll> A0,A1,B0,B1;

    rep(i,x){
      ll p= V[A[i]][m];
      if(p==0) A0.pb(A[i]);
      else A1.pb(A[i]);
    }
    rep(i,y){
      ll p=V[B[i]][m];
      if(p==0) B0.pb(B[i]);
      else B1.pb(B[i]);
    }

    auto a=dfs(A0,B1,m-1,V,num);
    auto b=dfs(A1,B0,m-1,V,num);
    auto c=dfs(A0,B0,m-1,V,num);
    auto d=dfs(B0,B1,m-1,V,num);

    ll ans=max(a.fi,max(b.fi,max(c.fi,d.fi)));

    if(ans==a.fi) return a;
    else if(ans==b.fi) return b;
    else if(ans==c.fi) return c;
    else return d;

}
