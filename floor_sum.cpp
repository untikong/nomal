// floor_sum(ll n,ll m,ll a,ll b)=(a*i+b)/m (i=0~n-1)
// o(logn+logm)
// https://atcoder.jp/contests/practice2/editorial/579

ll floor_sum(ll n, ll m, ll a,ll b){
  ll ans=0ll;
  ll p=a/m; ll q=b/m;
  ans+=p*n*(n-1)/2; ans+=q*n;
  a%=m; b%=m;
  if(a==0) return ans;
  ll y=(a*n+b)/m; ll z=(a*n+b)%m;
  ll bns=floor_sum(y,a,m,z);
  return ans+bns;
}
