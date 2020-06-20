rep(i,n-2){
   rep2(j,i+1,n-2){
     rep2(k,j+1,n-1){
       ll x1=A[j]-A[i] ; ll x2= A[k]-A[i] ;
       ll y1=B[j]-B[i] ; ll y2=B[k]-B[i] ;
       if(abs(x1*y2-x2*y1)%2ll==0&&x1*y2!=x2*y1) ans++ ;
     }
   }
 }
