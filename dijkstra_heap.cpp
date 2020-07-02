//　 ダイクストラ　ひーぷ　
/* dijkstra(G,s,dis)
    入力：グラフ G, 開始点 s, 距離を格納する dis
    計算量：O(|E|log|V|)
    副作用：dis が書き換えられる
*/
// グラフ　スタート　距離　ひとつ前
void dijkstra(const graph & g, ll s ,vector<ll> & d,vector<ll> &prev ){
   ll N = g.size() ; //頂点数
   d.resize(N,INF) ;
   prev.resize(N,INF) ;
   priority_queue<P,vector<P>,greater<P>> pq ;
   d[s]=0 ;
   pq.emplace(d[s],s) ;
   while(!pq.empty()){
       P p=pq.top() ;
       pq.pop() ;
       ll v= p.se;
       if(d[v]<p.fi) continue ;
       for(auto &e :g[v]){
           if(d[e.to]>d[v]+e.cost){
               d[e.to]=d[v]+e.cost ;
               prev[e.to]=v ;  //頂点vを使ってe.toに辿り着いた
               pq.emplace(d[e.to],e.to) ;
           }
       }
    } 
}

/* get_path(prev, t)
    入力：dijkstra で得た prev, ゴール t
    出力： t への最短路のパス
*/
vector<ll> get_path(const vector<ll> &prev, ll t) {
    vector<ll> path;
    for (ll cur = t; cur != -1; cur = prev[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end()); // 逆順なのでひっくり返す
    return path;
}
