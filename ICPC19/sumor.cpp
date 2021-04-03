#include "bits/stdc++.h"
using namespace std;
#include "vector"
#define endl '\n'
#ifndef dgb
#define dbg(...) (VA_ARGS)
#define dbgv(x)
#endif
#define pb push_back
#define eb emplace_back
#define rep(i, a, b) for(auto i = a;i != b;i++)
#define brep(i, a, b) for(auto i = a;i >= b;i--)
#define repi(i, a, b) for(auto i = a;i <= b;i++)
template<class t>t mag(t a){return a>0?a:-a;}
template <class T>T cdiv(T num,T den){return (num/den)+(num%den>0);}
std::ifstream term("/dev/tty");std::string tempstring;
using ll=int_fast64_t;using ii=pair<int,int>;using vi=vector<int>;
using vl=vector<ll>;using vii = vector<ii>;
int tc = 1;
const int sij = 400010;const ll mod = 1000000007ll;

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
int n;
int vec[sij], cur, ord[sij];
bool cmp(int i11, int i22){
  int i1 = vec[i11], i2 = vec[i22];
  brep(i, 29, 0){
    if((cur >> i) & 1){
      if(((i1 >> i) & 1) > ((i2 >> i) & 1)){
        return 1;
      }
      if(((i1 >> i) & 1) < ((i2 >> i) & 1)){
        return 0;
      }
    }
  }
  return 0;
}
int esc(int tcase){
  cin >> n;
  rep(i, 0, n){ cin >> vec[i];
  }
  iota(ord, ord + n, 0);

  cur = (1 << 30) - 1;
  rep(i, 0, min(30, n)){
    sort(ord + i, ord + n, cmp);
    rep(j, 0ll, 32){
      if((vec[ord[i]] >> j) & (1)){
        cur &= ~(1ll << j);      
      }
    }
  }
  ll prt = 0;
  int pre = 0;
  rep(i, 0, n){
    pre |= 1ll * vec[ord[i]];
    prt += pre;
  }
  cout << prt << endl;
  reverse(ord, ord + n);
  rep(i, 0, n){
    cout << ord[i] + 1 << ' ';
  }
  cout << endl;
  return 0;
}





int main(){
  //cout.precision(std::numeric_limits< double >::max_digits10);
  ios_base::sync_with_stdio(0);
#ifndef sep
  cin.tie(0);
  cout.tie(0);
#endif
  cin >> tc;
  for(int i = 1;i <= tc;i++)
    esc(i);
#ifdef sep
  cerr << "\n\nTime : "<<1.0* clock()/CLOCKS_PER_SEC << "s.\n\n";
#endif
}