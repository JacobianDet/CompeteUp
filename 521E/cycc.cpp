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
#define sz size
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

int ar[MV], dsc[MV], mdsc[MV], par[MV], deg[MV], lvl[MV];
ll arr[MV];
bool vis[MV], art[MV];
stack<int> S;
vector<PII> edg, G[MV];
VI TVC[MV], beg, pth[3];
int tx, x;

void dfs_vis1(int s, int p, int id)
{
    dsc[s] = mdsc[s] = ++tx;
    if((id != -1) && !vis[id])
    {
        S.push(id);
        vis[id] = 1;
    }       
    bool chd = 0;
    for(auto u : G[s])
    {
        if(u.ss == id)
        continue;
        else if(!dsc[u.ff])
        {
            dfs_vis1(u.ff, s, u.ss);
            mdsc[s] = min(mdsc[s], mdsc[u.ff]);
            if((p != -1) ? (mdsc[u.ff] >= dsc[s]) : chd)
            {
                art[s] = 1;
                x++;
                while(!S.empty() && (S.top() != u.ss))
                {   
                    TVC[x].pb(S.top());
                    S.pop();
                }
                if(!S.empty())
                {
                    TVC[x].pb(S.top());
                    S.pop();
                }       
            }   
            chd = 1;
        }
        else if(!vis[u.ss])
        {
            S.push(u.ss);
            vis[u.ss] = 1;
            mdsc[s] = min(mdsc[s], dsc[u.ff]);
        }       
    }
    return;
}

void dfs_vis2(int s, int id, int nd)
{
    dsc[s] = ++tx;
    if((id != -1) && !vis[id])
    vis[id] = 1; 
    for(auto u : G[s])
    {
        if(u.ss == id)
        continue;    
        else if(!dsc[u.ff])
        {
            lvl[u.ff] = 1 + lvl[s];
            par[u.ff] = s;
            dfs_vis2(u.ff, u.ss, nd);
        }    
        else if(!vis[u.ss])
        {
            vis[u.ss] = 1;
            if(u.ff == nd)
            beg.pb(s);    
        }    
    }
    return;    
}

void solve(int T)
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int s,d;
        cin>>s>>d;
        edg.pb({s, d});
        G[s].pb({d, i});
        G[d].pb({s, i});
    }   
    tx = 0, x = 0;
    for(int i=1;i<=n;i++)
    {
        par[i] = -1;
        if(!dsc[i])
        {   
            dfs_vis1(i, -1, -1);
            if(!S.empty())
            {   
                x++;
                while(!S.empty() && (S.top() != -1))
                {
                    TVC[x].pb(S.top());
                    S.pop();
                }
            }       
        }   
    }
    for(int i=1;i<=n;i++)
    {    
        dsc[i] = 0;
        G[i].clear();
    }   
    for(int i=0;i<m;i++)
    vis[i] = 0;     
    for(int i=1;i<=x;i++)
    {
        int nd = -1;
        for(auto &&u : TVC[i])
        {
            int s = edg[u].ff;
            int d = edg[u].ss;
            deg[s]++; deg[d]++;
            G[s].pb({d, u});
            G[d].pb({s, u});
            if(deg[s] >= 3)
            nd = s;
            if(deg[d] >= 3)
            nd = d;    
        }    
        if(nd != -1)
        {    
            tx = 0;
            dfs_vis2(nd, -1, nd);
            int t0 = beg[0], t1 = beg[1];
            if(lvl[t0] < lvl[t1])
            swap(t0, t1);
            int yt0 = t0, yt1 = t1, lc = -1;
            while(lvl[yt0] > lvl[t1])
            yt0 = par[yt0];
            if(yt0 == yt1)
            lc = yt0;
            else
            {    
                while(par[yt0] != par[yt1])
                {
                    yt0 = par[yt0];
                    yt1 = par[yt1];
                }
                lc = par[yt0];
            }       
            pth[0].pb(lc);
            yt0 = par[lc];
            while(yt0 != nd)
            {    
                pth[0].pb(yt0);
                yt0 = par[yt0];
            }    
            pth[0].pb(nd);
            reverse(begin(pth[0]), end(pth[0]));
            pth[1].pb(nd);
            pth[1].pb(t0);
            if(lc != t0)
            {    
                yt0 = par[t0];
                while(yt0 != lc)
                {
                    pth[1].pb(yt0);
                    yt0 = par[yt0];
                }
                pth[1].pb(lc);
            }    
            pth[2].pb(nd);
            pth[2].pb(t1);
            if(lc != t1)
            {    
                yt1 = par[t1];
                while(yt1 != lc)
                {
                    pth[2].pb(yt1);
                    yt1 = par[yt1];
                }
                pth[2].pb(lc);
            }    
            break;
        }    
        for(auto &&u : TVC[i])
        {
            int s = edg[u].ff;
            int d = edg[u].ss;
            deg[s]--; deg[d]--;
            vis[u] = 0;
            G[s].clear();
            G[d].clear();
        }
    } 
    if((int)pth[0].sz() == 0)
    cout<<"-1\n";
    else
    {
        cout<<pth[0][0]<<" "<<pth[0][(int)pth[0].sz()-1]<<"\n";
        for(int i=0;i<3;i++)
        {
            cout<<(int)pth[i].sz()<<" ";
            for(auto &&u : pth[i])
            cout<<u<<" ";
            cout<<"\n";    
        }    
    } 
    for(int i=1;i<=n;i++)
    {
        G[i].clear();
        lvl[i] = 0;
        par[i] = -1;
        dsc[i] = 0;
        deg[i] = 0;
        mdsc[i] = 0;
        art[i] = 0;
    } 
    for(int i=1;i<=x;i++)
    TVC[i].clear();
    for(int i=0;i<m;i++)
    vis[i] = 0;
    for(int i=0;i<3;i++)
    pth[i].clear();    
    edg.clear();
    beg.clear();    
    return; 
}

int main(void)
{
    FLASH();
    freopen("grand.in", "r", stdin);
    freopen("grand.out", "w", stdout);
    int T;
    T = 1;

#ifndef ONLINE_JUDGE
    time_t time_t1, time_t2;
    time_t1 = clock();
#endif

    cin>>T;
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