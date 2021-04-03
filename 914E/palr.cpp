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

int sze[MV], when[(1<<LMV)];
ll arr[MV], bt[(1<<LMV)];
bool isCrtd[MV];
string sd;
VI G[MV];
ll gs;
int tx;

void dfs_vis2(int s, int p)
{
	sze[s] = 1;
	for(auto u : G[s])
	{
		if((u != p) && !isCrtd[u])
		{
			dfs_vis2(u, s);
			sze[s] += sze[u];
		}	
	}
	return;
}

PII cent_find(int s, int p, int rt)
{
	int msz = 0;
	PII centroid = {0, MV};
	for(auto u : G[s])
	{
		if((u != p) && !isCrtd[u] && (sze[s] > sze[rt]/2))
		{
			PII px = cent_find(u, s, rt);
			if(centroid.ss > px.ss)
			centroid = px;
			msz = max(msz, sze[u]);	
		}	
	}
	msz = max(msz, sze[rt]-sze[s]);
	if(centroid.ss > msz)
	centroid = {s, msz};
	return centroid;	
}

void dfs_sol2(int s, int p, int vl, int add)
{
	vl ^= (1<<(sd[s-1] - 'a'));
	if(when[vl] != tx)
	{
		when[vl] = tx;
		bt[vl] = 0;
	}	
	bt[vl] += add;
	for(auto u : G[s])
	{
		if((u != p) && !isCrtd[u])
		dfs_sol2(u, s, vl, add);	
	}
	return;
}

ll dfs_sol3(int s, int p, int vl)
{
	vl ^= (1<<(sd[s-1] - 'a'));
	ll tt = 0;
	for(int i=0;i<20;i++)
	{
		if(when[vl ^ (1<<i)] == tx)
		tt += bt[vl ^ (1<<i)];
		if(!(vl ^ (1<<i)))
		{
			gs++;
			tt++;
		}	
	}
	if(when[vl] == tx)
	tt += bt[vl];
	if(!vl)
	{
		gs++;
		tt++;
	}		
	for(auto u : G[s])
	{
		if((u != p) && !isCrtd[u])
		tt += dfs_sol3(u, s, vl);	
	}
	arr[s] += tt;
	return tt;
}

void dfs_sol1(int s, int compsz)
{
	tx++;
	for(auto u : G[s])
	{
		if(!isCrtd[u])
		dfs_sol2(u, s, 0, 1);	
	}
	gs = 0;
	for(auto u : G[s])
	{
		if(!isCrtd[u])
		{
			dfs_sol2(u, s, 0, -1);
			gs += dfs_sol3(u, s, (1<<(sd[s-1] - 'a')));
			dfs_sol2(u, s, 0, 1);
		}
	}
	gs >>= 1LL;
	arr[s] += gs;
	return;
}

void dfs_vis1(int s)
{
	dfs_vis2(s, -1);
	PII centroid = cent_find(s, -1, s);
	dfs_sol1(centroid.ff, sze[s]);
	isCrtd[centroid.ff] = 1;
	for(auto u : G[centroid.ff])
	{
		if(!isCrtd[u])
		dfs_vis1(u);	
	}
	return;
}

void solve(int T)
{
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}	
	cin>>sd;
	tx = 0;
	dfs_vis1(1);
	for(int i=1;i<=n;i++)
	{
		arr[i]++;
		cout<<arr[i]<<" \n"[i == n];
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