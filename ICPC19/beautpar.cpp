#include "bits/stdc++.h"
using namespace std;
#include "vector"
#define endl '\n'
#ifndef dgb
//#define //dbg(...) (VA_ARGS)
//#define //dbgv(x)
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
const int sij = 600010;const ll mod = 1000000007ll;
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


int n, k;
ll vec[sij], pre[sij], fen[sij], ans[sij], par[sij];

bool cmp(int i, int j){
  return pre[i] < pre[j];
}

void update(int ind, int val){
  while(ind <=n){
//    fen[ind] = max(fen[ind], val);
    if(ans[fen[ind]] < ans[val]){
      fen[ind] = val;
    }
    ind += (ind & -ind);
  }
}

int get(int ind){
  int ret = 0;
  while(ind){
    if(ans[fen[ind]] > ans[ret]){
      ret = fen[ind];
    }
//    ret = max(ret, fen[ind]);
    ind -= (ind & -ind);
  }
  return ret;
}

int esc(int tcase){
  cin >> n >> k;
  repi(i, 1, n) cin >> vec[i];
  repi(i, 1, n) pre[i] = pre[i - 1] + vec[i];
  if(pre[n] <= 0){
    cout << "NO\n";
    return 0;
  }
  unordered_map<ll, int, custom_hash> mp;
  int cnt = 0;
  ll pr = -1;
  set<ll> all;
  repi(i, 1, n) if(pre[i] > 0)  all.insert(pre[i]);
  for(auto &e:all){
    mp[e] = ++cnt;
  }
  memset(fen, 0, sizeof(fen) / sij * (n + 10));
  memset(ans, 0, sizeof(ans) / sij * (n + 10));
  memset(par, 0, sizeof(par) / sij * (n + 10));
  repi(i, 1, n){
    ////dbg(i, pre[i], mp[pre[i]]);
    if(pre[i] <= 0) continue;
    auto xx = get(mp[pre[i]] - 1);
    ////dbg(i, pre[i], xx, ans[xx]);
    ans[i] = ans[xx] + 1;
    par[i] = xx;
    update(mp[pre[i]], i);
  }
  if(ans[n] < k){
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  vector<int> prt;
  int cur = n;
  while(cur > 0 and prt.size() < k - 1){
    prt.pb(cur - par[cur]);
    cur = par[cur];
  }
  prt.pb(cur);
  reverse(prt.begin(), prt.end());
  for(auto &e:prt){
    cout << e << ' ';
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