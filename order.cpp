 map<ll,ll> factor(ll n){  //素因数とオーダーをマップで管理
  map <ll,ll> ord ;  
  for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            int res=0;
            while(n%i==0){
                n/=i;
                res++;
            }
            ord[i]=res;
        }
    }
   if(n!=1) ord[n]++;
   return ord ;
 }
