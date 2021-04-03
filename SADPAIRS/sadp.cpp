#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define MV 500001
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

int ar[MV], dsc[MV], mdsc[MV], cord[MV], droc[MV], sze[MV];
ll arr[2*MV], xdr[2*MV], txt[MV];
bool vis[MV], art[MV], big[MV];
vector<PII> edg, G[MV];
stack<int> S;
VI TVC[MV], tnx[MV], clx, tclx;
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

void dfs_vis2(int s, int p, int add)
{
	sze[s] = 1;
	vis[s] = 1;
	for(auto u : tnx[s])
	arr[ar[u]] += add;		
	for(auto u : G[s])
	{
		if(u.ff != p)
		{
			dfs_vis2(u.ff, s, add);
			sze[s] += sze[u.ff];
		}	
	}
	return;
}

void dfs_sack2(int s, int p, int add)
{
	for(auto u : tnx[s])
	{
		xdr[ar[u]] += add;
		arr[ar[u]] -= add;
		clx.pb(u);
	}	
	for(auto u : G[s])
	{
		if((u.ff != p) && !big[u.ff])
		dfs_sack2(u.ff, s, add);	
	}
	return;
}

ll dfs_calc(int s, int p)
{
	ll rz = 0;
	for(auto u : tnx[s])
	rz += arr[ar[u]];
	for(auto u : G[s])
	{
		if(u.ff != p)
		rz += dfs_calc(u.ff, s);	
	}
	return rz;
}

void dfs_sack1(int s, int p, int keep)
{
	int hsz = 0, hed = 0;
	for(auto u : G[s])
	{
		if(u.ff != p)
		{
			if(hsz < sze[u.ff])
			{
				hsz = sze[u.ff];
				hed = u.ff;
			}	
		}
	}
	for(auto u : G[s])
	{
		if((u.ff != p) && (u.ff != hed))
		dfs_sack1(u.ff, s, 0);	
	}
	if(hed)
	{
		big[hed] = 1;
		dfs_sack1(hed, s, 1);	
	}
	for(auto u : G[s])
	{
		if((u.ff != p) && !big[u.ff])
		{
			dfs_sack2(u.ff, s, 0);
			if(s > x)
			{
				for(auto &&e : clx)
				txt[droc[s]] += xdr[ar[e]];
			}	
			for(auto &&e : clx)
			{
				tclx.pb(e);
				xdr[ar[e]]++;
				arr[ar[e]]--;
			}	
			clx.clear();
		}	
	}
	for(auto u : tnx[s])
	{	
		xdr[ar[u]]++;
		arr[ar[u]]--;
	}	
	if(s > x)
	{
		for(auto &&e : tclx)
		txt[droc[s]] += arr[ar[e]];
	}		
	for(auto u : tnx[s])
	{
		xdr[ar[u]]--;
		txt[u] += (arr[ar[u]] + xdr[ar[u]]);
		xdr[ar[u]]++;
		tclx.pb(u);
	}	
	if(hed)
	big[hed] = 0;
	if(!keep)
	{
		tclx.clear();
		dfs_sack2(s, p, -1);
		clx.clear();
	}	
	return;
}

void solve(int T)
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>ar[i];
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
    VI arp;
    for(int i=1;i<=x;i++)
    {
    	VI tnn;
    	for(auto &&u : TVC[i])
    	{
    		int s = edg[u].ff;
    		int d = edg[u].ss;
    		if(!art[s])
    		tnn.pb(s);
    		else arp.pb(s);
    		if(!art[d])
    		tnn.pb(d);
    		else arp.pb(d);
    	}
    	sort(begin(tnn), end(tnn));
    	tnn.resize(unique(begin(tnn), end(tnn)) - begin(tnn));
    	for(auto &&u : tnn)
    	{	
    		cord[u] = i;
    		tnx[i].pb(u);
    	}	
    }
    sort(begin(arp), end(arp));
    arp.resize(unique(begin(arp), end(arp)) - begin(arp));
    int xt = x;
    for(auto &&u : arp)
    {
    	cord[u] = ++xt;
    	droc[xt] = u;
    	tnx[xt].pb(u);
    }
    for(int i=1;i<=n;i++)
    {
    	if(!cord[i])
    	{
    		cord[i] = ++xt;
    		droc[xt] = i;
    		tnx[xt].pb(i);
    	}	
    }	
    arp.clear();
    for(int i=0;i<m;i++)
    vis[i] = 0;	
    for(int i=1;i<=n;i++)
    G[i].clear();	
	for(int i=1;i<=x;i++)
	{
		for(auto &&u : TVC[i])
		{
			int s = cord[edg[u].ff];
			int d = cord[edg[u].ss];
			if(s > x)
			arp.pb(s);
			if(d > x)
			arp.pb(d);	
		}	
		sort(begin(arp), end(arp));
		arp.resize(unique(begin(arp), end(arp)) - begin(arp));
		for(auto &&u : arp)
		{
			G[u].pb({i, -1});
			G[i].pb({u, -1});
		}
		arp.clear();	
	}
	for(int i=1;i<=xt;i++)
	{
		if(!vis[i])
		{
			dfs_vis2(i, -1, 1);
			dfs_sack1(i, -1, 0);
			dfs_vis2(i, -1, -1);
		}	
	}
	for(int i=1;i<=xt;i++)
	vis[i] = 0;
	ll tt = 0;
	for(int i=1;i<=xt;i++)
	{
		if(!vis[i])
		{
			tt += dfs_calc(i, -1);
			dfs_vis2(i, -1, 1);
		}	
	}
	for(int i=1;i<=n;i++)
	cout<<(tt + txt[i])<<"\n";
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