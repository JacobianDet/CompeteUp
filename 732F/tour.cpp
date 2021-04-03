#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define MV 400001
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

int ar[MV], lvl[MV], brc[MV], vis[MV];
int tx;
vector<PLL> G[MV];
VI TEC[MV], brg;
vector<PPII> edg;

void dfs_vis1(int s)
{
	for(auto e : G[s])
	{
		int u = e.ff;
		if(!lvl[u])
		{
			lvl[u] = 1 + lvl[s];
			dfs_vis1(u);
			brc[s] += brc[u];
		}
		else
		{
			if(lvl[u] < lvl[s])
			brc[s]++;
			else brc[s]--;	
		}
	}
	brc[s]--;
	if((lvl[s] > 1) && (brc[s] == 0))
	brg.pb(s);
	return;	
}

void dfs_vis2(int s, int x)
{
	ar[s] = x;
	TEC[x].pb(s);
	for(auto e : G[s])
	{
		int u = e.ff;
		if((lvl[u] > lvl[s]) && !ar[u])
		dfs_vis2(u, x);
	}
	return;
}

void dfs_vis3(int s)
{
	vis[s] = ++tx;
	for(auto e : G[s])
	{
		int u = e.ff;
		if(!vis[u])
		{
			if(ar[s] != ar[u])
			edg.pb({{u, s}, e.ss});
			else edg.pb({{s, u}, e.ss});
			dfs_vis3(u);	
		}	
		else if((ar[s] == ar[u]) && (vis[u] > vis[s]))
		edg.pb({{u, s}, e.ss});
	}
	return;
}

void solve(int T)
{
	tx = 0;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int s,d;
		cin>>s>>d;
		G[s].pb({d, i});
		G[d].pb({s, i});
	}
	lvl[1] = 1;	
	dfs_vis1(1);
	int x = 0;
	for(auto u : brg)
	{
		x++;
		dfs_vis2(u, x);
	}
	for(int i=1;i<=n;i++)
	{
		if(!ar[i])
		{
			x++;
			dfs_vis2(i, x);
		}	
	}
	int yt = 0, mz = 0;
	for(int i=1;i<=x;i++)
	{
		if((int)TEC[i].sz() > mz)
		{
			mz = (int)TEC[i].sz();
			yt = i;
		}	
	}
	dfs_vis3(TEC[yt][0]);
	sort(begin(edg), end(edg), [](PPII A, PPII B){ return (A.ss < B.ss); });
	cout<<mz<<"\n";
	for(auto u : edg)
	cout<<u.ff.ff<<" "<<u.ff.ss<<"\n";
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