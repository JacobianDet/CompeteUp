#include <map>
#include <set>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long       LL;
typedef pair<int, int>  PII;
typedef vector<int>     VI;
typedef vector<LL>      VL;
typedef vector<PII>     VPII;
#define MM(a,x) memset(a,x,sizeof(a));
#define ALL(x)  (x).begin(), (x).end()
#define P(x)    cerr<<"["#x<<" = "<<(x)<<"]\n"
#define PP(x,i)    cerr<<"["#x<<i<<" = "<<x[i]<<"]\n"
#define P2(x,y)    cerr<<"["#x" = "<<(x)<<", "#y" = "<<(y)<<"]\n"
#define TM(a,b)    cerr<<"["#a" -> "#b": "<<1e3*(b-a)/CLOCKS_PER_SEC<<"ms]\n";
#define UN(v) sort(ALL(v)), v.resize(unique(ALL(v))-v.begin())
#define mp make_pair
#define pb push_back
#define x first
#define y second
struct _ {_() {ios_base::sync_with_stdio(0);}} _;
template<class A, class B> ostream& operator<<(ostream &o, pair<A, B> t) {o << "(" << t.x << ", " << t.y << ")"; return o;}
template<class T> void PV(T a, T b) {while(a != b)cout << *a++, cout << (a != b ? " " : "\n");}
template<class T> inline bool chmin(T &a, T b) {return a > b ? a = b, 1 : 0;}
template<class T> inline bool chmax(T &a, T b) {return a < b ? a = b, 1 : 0;}
template<class T> string tostring(T x, int len = 0) {stringstream ss; ss << x; string r = ss.str(); if(r.length() < len) r = string(len - r.length(), '0') + r; return r;}
template<class T> void convert(string x, T& r) {stringstream ss(x); ss >> r;}
const int inf = 0x3f3f3f3f;
const long long linf = 0x3f3f3f3f3f3f3f3fLL;
const int mod = int(1e9) + 7;
const int N = 15111111;

int n, m;

int F[N];

inline LL exp(LL x, LL n, LL m = mod) {
    LL r = 1;
    while(n) {
        if(n & 1) r = r * x % m;
        x = x * x % m, n >>= 1;
    }
    return r;
}

int main() {
    cin >> n >> m;
    if(n > m) swap(n, m);

    time_t t1 = clock();
    for(int i = 1; i < N; i++) F[i] = (LL)(n / i) * (m / i) % (mod - 1);

    for(int i = n; i >= 1; i--)
        for(int j = i + i; j <= n; j += i) {
            F[i] -= F[j];
            if(F[i] < 0) F[i] += mod - 1;
        }

    int res = 1;
    for(int i = 1; i <= n; i++) res = res * exp(i, F[i]) % mod;
    cout << res << endl;

    /*
    {
        int br = 1;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                br = (LL) br * __gcd(i, j) % mod;
        cout << br << endl;
        assert(br == res);
    }
    */

    time_t t2 = clock();
    TM(t1, t2);

    return 0;
}