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

int ar[MV], sze[MV], deg[MV], lvl[MV];
ll arr[MV];
bool vis[MV];
VI G[MV], D[MV];
vector<PII> edg;
int n,k;

int dfs_vis1(int s, int p)
{
	int mx = -1;
	for(auto u : G[s])
	{
		if(u != p)
		{
			mx = max(mx, dfs_vis1(u, s));
			sze[s] += sze[u];
		}	
	}
	sze[s] += !!ar[s];
	if(sze[s] == k)
	{
		if(mx == -1)
		mx = s;
		else sze[s] = 0;
	}
	return mx;	
}

PII centre_find(void)
{
	queue<int> Q;
	for(int i=1;i<=n;i++)
	{
		deg[i] = sz(D[i]);
		if(deg[i] == 1)
		{
			lvl[i] = 0;
			Q.push(i);
		}		
	}	
	PII fx = {-1, -1};
	int mh = 0;
	while(!Q.empty())
	{
		int s = Q.front();
		Q.pop();
		vis[s] = 1;
		for(auto u : D[s])
		{
			if(!vis[u])
			{
				deg[u]--;
				if(deg[u] == 1)
				{
					lvl[u] = 1 + lvl[s];
					if(mh < lvl[u])
					{
						mh = lvl[u];
						fx.ff = u;
						fx.ss = -1;
					}	
					else if(mh == lvl[u])
					fx.ss = u;	
					Q.push(u);	
				}	
			}	
		}
	}
	return fx;
}

void dfs_vis2(int s, int p)
{
	lvl[s] = 0;
	if(p != -1)
	lvl[s] = 1 + lvl[p];
	for(auto u : G[s])
	{
		if(u != p)
		dfs_vis2(u, s);	
	}	
	return;
}

void solve(int T)
{
	cin>>n>>k;
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		cin>>s>>d;
		edg.pb({s, d});
		G[s].pb(d);
		G[d].pb(s);
	}
	for(int i=0;i<k;i++)
	{
		int t;
		cin>>t;
		ar[t] = 1;
	}	
	int fn = dfs_vis1(1, -1);
	for(auto &&u : edg)
	{
		int s = u.ff, d = u.ss;
		if(sze[s] && sze[d])
		{
			D[s].pb(d);
			D[d].pb(s);
		}
	}
	bool ok = 1;
	for(int i=1;i<=n;i++)
	ok &= !sz(D[i]);
	if(ok)
	cout<<"0\n";
	else
	{
		PII nd = centre_find();
		dfs_vis2(nd.ff, -1);
		int vf = -1, mf = 0;
		for(int i=1;i<=n;i++)
		{
			if(ar[i])
			{
				if(vf == -1)
				{
					vf = !!(lvl[i] & 1);
					mf = max(mf, lvl[i]);
				}
				else if(((!!(lvl[i] & 1)) == vf))
				mf = max(mf, lvl[i]);
				else
				{
					mf = -1;
					break;
				}	
			}
		}
		cout<<mf<<"\n";	
	}
	edg.clear();
	for(int i=1;i<=n;i++)
	{
		G[i].clear();
		D[i].clear();
		deg[i] = 0;
		ar[i] = 0;
		lvl[i] = 0;
		vis[i] = 0;
		sze[i] = 0;
	}	
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