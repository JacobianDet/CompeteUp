#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define MV 200001
#define LMV 21
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define emp emplace
#define mp make_pair
#define ins insert
#define sz(x) (int)x.size()
#define whoami(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); whi(_it, args); }

void whi(istream_iterator<string> it) { cerr<<"\n"; }

template<typename T, typename... Args>
void whi(istream_iterator<string> it, T a, Args... args) { cerr<<*it<<" "<<a<<" "; whi(++it, args...); }

void FLASH() {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
void SETF() {cout.ios_base::setf(ios_base::fixed); cerr.ios_base::setf(ios_base::fixed);}
void UNSETF() {cout.ios_base::unsetf(ios_base::fixed); cerr.ios_base::unsetf(ios_base::fixed);}

typedef long long ll;
typedef long double ld;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef pair<PII, int> PPII;
typedef pair<PLL, ll> PPLL;
typedef map<int, int> MII;

const int MOD = 998244353;
const ll INF = 4e18;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct h_llint {
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

struct h_pair{
    size_t operator()(const PLL&x)const{
        return hash<ll>()(((ll)x.ff)^(((ll)x.ss)<<32));
    }
};

typedef map<ll, ll> MLL;
typedef map<PII, int> MPII;
typedef map<PLL, ll> MPLL;
typedef set<int> SI;
typedef set<ll> SL;
//ordered_set = order_of_key(.)
//ordered_set = find_by_order(.)
typedef ordered_set<int> OSI;
typedef ordered_set<ll> OSL;
typedef ordered_multiset<int> MOSI;
typedef ordered_multiset<ll> MOSL;
typedef unordered_map<ll, int, h_llint> UMLI;
typedef unordered_map<ll, ll, h_llint> UMLL;
typedef unordered_map<PLL, int, h_pair> UMPI;
typedef unordered_map<PLL, ll, h_pair> UMPL;

int ar[MV];
ll arr[MV];
vector<vector<char> > G;
vector<VI> rf, uf;
vector<VL> memo;
int h,w;

ll modexp(ll a, ll n)
{
    ll res = 1;
    while(n)
    {
        if(n & 1)
        res = ((res%MOD) * (a%MOD))%MOD;
        a = ((a%MOD) * (a%MOD))%MOD;
        n >>= 1;
    }
    return res;
}

// ll xd(int ix, int jx)
// {
//     // whoami(ix, jx);
//     if((ix == h) && (jx == w))
//     return modexp(3, uf[ix-1][jx-1])%MOD;
//     else if((ix > h) || (jx > w))
//     return 0;
//     if(memo[ix][jx] != -1)
//     return memo[ix][jx];
//     ll ans = 0;
//     if(G[ix-1][jx-1] == '.')
//     {
//         ans += (modexp(3, uf[ix-1][jx-1]-1) * xd(ix, jx+1))%MOD;
//         ans %= MOD;
//         ans += (modexp(3, rf[ix-1][jx-1]-1) * xd(ix+1, jx))%MOD;
//         ans %= MOD;
//         ans = (2 * ans)%MOD;
//     }
//     else if(G[ix-1][jx-1] == 'R')
//     {
//         ans += (modexp(3, uf[ix-1][jx-1]) * xd(ix, jx+1))%MOD;
//         ans %= MOD;
//     }    
//     else if(G[ix-1][jx-1] == 'D')
//     {
//         ans += (modexp(3, rf[ix-1][jx-1]) * xd(ix+1, jx))%MOD;
//         ans %= MOD;
//     }
//     else
//     {
//         ans += (modexp(3, uf[ix-1][jx-1]) * xd(ix, jx+1))%MOD;
//         ans %= MOD;
//         ans += (modexp(3, rf[ix-1][jx-1]) * xd(ix+1, jx))%MOD;
//         ans %= MOD;
//     }
//     memo[ix][jx] = ans;
//     // whoami(ix, jx, ans);
//     return ans;
// }

void solve(int T)
{
    int k;
    cin>>h>>w>>k;
    G.resize(h, vector<char>(w, '.'));
    rf.resize(h, VI(w, 0));
    uf.resize(h, VI(w, 0));
    memo.resize(h+5, VL(w+5, 0));
    for(int i=0;i<k;i++)
    {
        int ph,pw;
        cin>>ph>>pw;
        char pc;
        cin>>pc;
        G[ph-1][pw-1] = pc;
    }
    for(int i=h-1;i>=0;i--)
    {
        for(int j=w-1;j>=0;j--)
        {
            if(G[i][j] == '.')
            rf[i][j]++;
            if(j < w-1)
            rf[i][j] += rf[i][j+1];
        }
    }
    for(int i=w-1;i>=0;i--)
    {
        for(int j=h-1;j>=0;j--)
        {
            if(G[j][i] == '.')
            uf[j][i]++;
            if(j < h-1)
            uf[j][i] += uf[j+1][i];
        }
    }
    for(int i=0;i<max(h+5, w+5);i++)
    arr[i] = modexp(3, i)%MOD;
    memo[h][w] = arr[uf[h-1][w-1]]%MOD;
    for(int i=h;i>0;i--)
    {
        for(int j=w;j>0;j--)
        {
            if((i == h) && (j == w))
            continue;
            if(G[i-1][j-1] == '.')
            {
                memo[i][j] += (arr[uf[i-1][j-1]-1] * memo[i][j+1])%MOD;
                memo[i][j] %= MOD;
                memo[i][j] += (arr[rf[i-1][j-1]-1] * memo[i+1][j])%MOD;
                memo[i][j] %= MOD;
                memo[i][j] = (2 * memo[i][j])%MOD;
            }
            else if(G[i-1][j-1] == 'R')
            {
                memo[i][j] += (arr[uf[i-1][j-1]] * memo[i][j+1])%MOD;
                memo[i][j] %= MOD;
            }   
            else if(G[i-1][j-1] == 'D')
            {
                memo[i][j] += (arr[rf[i-1][j-1]] * memo[i+1][j])%MOD;
                memo[i][j] %= MOD;
            }
            else
            {
                memo[i][j] += (arr[uf[i-1][j-1]] * memo[i][j+1])%MOD;
                memo[i][j] %= MOD;
                memo[i][j] += (arr[rf[i-1][j-1]] * memo[i+1][j])%MOD;
                memo[i][j] %= MOD;
            } 
        }
    }
    cout<<memo[1][1]<<"\n";
    return;
}

int main(void)
{
    FLASH();
    //freopen("cowjog.in", "r", stdin);
    //freopen("cowjog.out", "w", stdout);
    int T;
    T = 1;

#ifndef ONLINE_JUDGE
    time_t time_t1, time_t2;
    time_t1 = clock();
#endif

    //cin>>T;
    while(T--)
    solve(T);

#ifndef ONLINE_JUDGE
    time_t2 = clock();
    SETF();
    cerr<<"Time taken: "<<setprecision(7)<<(time_t2 - time_t1)/(double)CLOCKS_PER_SEC<<"\n";
    UNSETF();
#endif

    return 0;
}