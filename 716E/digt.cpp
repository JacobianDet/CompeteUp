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

int sze[MV], lvl[MV];
bool isCrtd[MV];
MLL hup;
vector<PPII> upa, tupa;
VI nsz;
int mx, pmx;
vector<PII> G[MV];

ll modexp(ll a, ll n, ll mx)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)
		res = ((res%mx) * (a%mx))%mx;
		a = ((a%mx) * (a%mx))%mx;
		n >>= 1;	
	}
	return res;
}

void dfs_vis2(int s, int p)
{
	sze[s] = 1;
	for(auto u : G[s])
	{
		if((u.ff != p) && !isCrtd[u.ff])
		{
			dfs_vis2(u.ff, s);
			sze[s] += sze[u.ff];	
		}
	}
	return;
}

PII cent_find(int s, int p, int rt)
{
	PII centroid = {0, MV};
	int msz = 0;
	for(auto u : G[s])
	{
		if((u.ff != p) && !isCrtd[u.ff] && (sze[u.ff] > sze[rt]/2))
		{
			PII px = cent_find(u.ff, s, rt);
			if(centroid.ss > px.ss)
			centroid = px;
			msz = max(msz, sze[u.ff]);
		}	
	}
	msz = max(msz, sze[rt] - sze[s]);
	if(centroid.ss > msz)
	centroid = {s, msz};
	return centroid;	
}

void dfs_sol2(int s, int p, int up, int dwn)
{
	int upx = (((mx - dwn)%mx) * (modexp((modexp(10, lvl[s], mx)%mx), pmx-1, mx)%mx))%mx;
	upa.pb({{up, dwn}, upx});
	tupa.pb({{up, dwn}, upx});
	for(auto u : G[s])
	{
		if((u.ff != p) && !isCrtd[u.ff])
		{
			lvl[u.ff] = lvl[s] + 1;
			int nu = ((((modexp(10, lvl[u.ff]-1, mx)%mx) * (u.ss%mx))%mx) + (up%mx))%mx;
			int nd = ((((10LL%mx) * (dwn%mx))%mx) + (u.ss%mx))%mx;
			dfs_sol2(u.ff, s, nu, nd);
		}		
	}
	return;
}

ll dfs_sol1(int s, int compsz)
{
	ll rz = 0;
	lvl[s] = 0;
	for(auto u : G[s])
	{
		if(isCrtd[u.ff])
		continue;	
		lvl[u.ff] = 1 + lvl[s];
		dfs_sol2(u.ff, s, u.ss%mx, u.ss%mx);
		for(auto &&e : upa)
		{	
			rz += hup[e.ss];
			rz += !e.ff.ff;
			rz += !e.ff.ss;
		}		
		for(auto &&e : upa)
		hup[e.ff.ff]++;
		nsz.pb((int)upa.sz());
		upa.clear();	
	}
	int uy = 0;
	for(int i=0;i<(int)nsz.sz();i++)
	{
		for(int j=uy;j<uy+nsz[i];j++)
		hup[tupa[j].ff.ff]--;	
		for(int j=uy;j<uy+nsz[i];j++)
		rz += hup[tupa[j].ss];
		uy += nsz[i];			
	}
	nsz.clear();
	hup.clear();
	tupa.clear();
	return rz;
}

ll dfs_vis1(int s)
{
	dfs_vis2(s, -1);
	PII centroid = cent_find(s, -1, s);
	ll rz = dfs_sol1(centroid.ff, sze[s]);
	isCrtd[centroid.ff] = 1;
	for(auto u : G[centroid.ff])
	{
		if(!isCrtd[u.ff])
		rz += dfs_vis1(u.ff);	
	}	
	return rz;
}

void solve(int T)
{
	int n;
	cin>>n>>mx;
	int tmx = mx;
	pmx = 1;
	for(int i=2;i*i<=tmx;i++)
	{
		if(tmx % i)
		continue;
		while(!(tmx % i))
		{
			pmx *= i;
			tmx /= i;
		}	
		pmx = (pmx/i) * (i-1);
	}
	if(tmx > 1)
	pmx = pmx * (tmx-1);
	for(int i=0;i<n-1;i++)
	{
		int s,d,w;
		cin>>s>>d>>w;
		s++, d++;
		G[s].pb({d, w});
		G[d].pb({s, w});
	}	
	ll res = dfs_vis1(1);
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