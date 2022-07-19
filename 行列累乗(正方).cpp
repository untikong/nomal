//縦横nの正方行列Aのx乗

ll n ;
vector<vector<mint>> mat(vector<vector<mint>>&A,ll x){
  vector<vector<mint>> zero(n,vector<mint> (n,0));
  rep(i,n) zero[i][i]=1;
  if(x==0) return zero;
  if(x==1) return  A ;
  vector<vector<mint>> B(n,vector<mint>(n,0)) ;
  vector<vector<mint>> C(n,vector<mint>(n,0)) ;
  vector<vector<mint>> V=mat(A,x/2) ;
  rep(i,n)rep(j,n){
    rep(k,n) B[i][j]+=V[i][k]*V[k][j] ;
  }
  if(x%2==0){
    return B ;
  }
  else{
      rep(i,n)rep(j,n){
        rep(k,n) C[i][j]+=B[i][k]*A[k][j] ;
      }
      return C ;
  }
}
