//vector<ll> p(n)について p,nを変えて使う
  //next[i]は[0,i]の接頭辞と接頭尾x文字が一致するようなxの最大値(x<(i+1))
  vector<ll> next(n) ;
  next[0]=0ll ;
  rep(i,n-1){
   ll now=i ;
   while(now>=0){
   ll k=next[now] ;
   if(p[i+1]==p[k]){
     next[i+1]=next[now]+1 ; 
     break ;
    }
    now=next[now]-1 ;
   }
   if(now<0) next[i+1]=0 ;
  }
  //vector<ll> q(m)からp(n)を探す
  vector<ll> memo ; //memoの要素xは先頭q[x]の部分列が一致する事を表す
  ll now=0 ;
  ll same=0 ;
  while(now+n<m){
    //same何文字一致している 
   ll have=same ;
   rep(j,n-have){
     if(q[now+j+have]!=p[j+have]){
       break ;
     }
     else same++ ;
   }
   if(same==n) memo.pb(now) ;
   if(same==0){ 
     now++ ;
     continue ;
   }
   now+=same-next[same-1] ;
   same=next[same-1] ;
  }
