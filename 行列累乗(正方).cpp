//縦横nの正方行列Aのx乗
ll n ;
vector<vector<mint>> mat(vector<vector<mint>>&A,ll x){
  if(x==1) return  A ;
  vector<vector<mint>> B(n,vector<mint>(n,0)) ;
  vector<vector<mint>> C(n,vector<mint>(n,0)) ;
  vector<vector<mint>> V=mat(A,x/2) ;
   rep(i,n)rep(j,n){
     mint now=0 ;
     rep(k,n) now+=V[i][k]*V[k][j] ;
     B[i][j]=now ;
   }
   if(x%2==0){
     return B ;
   }
    else{
      rep(i,n)rep(j,n){
      mint now=0ll ;
      rep(k,n) now+=B[i][k]*A[k][j] ;
      C[i][j]=now ;
    }
    return C ;
   }
}
