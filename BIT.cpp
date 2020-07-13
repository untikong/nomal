// sum(x) x以下の和
// sum(a,b) a以上b以下の和
template<typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n=0):n(n),d(n+1) {}
  void add(int i, T x=1) {  //x=1ならsumは個数のカウント
    for (i++; i <= n; i += i&-i) {
      d[i] += x;
    }
  }
  T sum(int i) {
    T x = 0;
    for (i++; i; i -= i&-i) {
      x += d[i];
    }
    return x;
  }
  T sum(int i,int j) { return sum(j)-sum(min(i-1,0)) }
};
