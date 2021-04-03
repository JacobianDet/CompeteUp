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

const int MOD = 1000000007;
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
bool vis[MV];
ll arr[MV], memo[18][(1<<17)], dist[18][MV];
VI G[MV], gf;

int dfs_visit(int s)
{
    vis[s] = 1;
    int cc = ar[s];
    for(auto u : G[s])
    {
        if(!vis[u])
        cc += dfs_visit(u);
    }
    return cc;
}

void bfs_visit(int yt, int n)
{
    for(int i=1;i<=n;i++)
    dist[yt][i] = MOD;
    dist[yt][gf[yt]] = 0;
    vis[gf[yt]] = 1;
    queue<int> Q;
    Q.push(gf[yt]);
    while(!Q.empty())
    {
        int s = Q.front();
        Q.pop();
        for(auto u : G[s])
        {
            if(!vis[u])
            {
                dist[yt][u] = min(dist[yt][u], dist[yt][s] + 1);
                vis[u] = 1;
                Q.push(u);
            }
        }
    }
    return;
}

ll xd(int ix, int mask)
{
    if(!mask)
    return 0;
    if(memo[ix][mask] != -1)
    return memo[ix][mask];
    ll ans = MOD;
    if(ix == sz(gf))
    {
        int nm = mask;
        for(auto u=__builtin_ctz(nm);nm;(nm ^= (1<<u)), u=__builtin_ctz(nm))
        ans = min(ans, 1 + xd(u, mask ^ (1<<u)));
    }
    else
    {
        int nm = mask;
        for(auto u=__builtin_ctz(nm);nm;(nm ^= (1<<u)), u=__builtin_ctz(nm))
        ans = min(ans, dist[ix][gf[u]] + xd(u, mask ^ (1<<u)));
    }
    memo[ix][mask] = ans;
    return ans;
}

void solve(int T)
{
    memset(memo, -1, sizeof(memo));
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int s,d;
        cin>>s>>d;
        G[s].pb(d);
        G[d].pb(s);
    }
    int k;
    cin>>k;
    gf.resize(k);
    for(auto &&u : gf)
    {
        cin>>u;
        ar[u] = 1;
    }   
    int rc = -1; 
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(dfs_visit(i) == k)
            rc = i;
        }
    }
    if(rc == -1)
    {
        cout<<"-1\n";
        return;
    }
    for(int i=0;i<k;i++)
    {
        for(int j=1;j<=n;j++)
        vis[j] = 0;
        bfs_visit(i, n);
    }    
    ll res = xd(k, (1<<k)-1);
    cout<<res<<"\n";
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