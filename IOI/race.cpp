#include "grader.h"
#include <bits/stdc++.h>
using namespace std;
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
typedef unordered_map<ll, int, h_llint> UMLI;
typedef unordered_map<ll, ll, h_llint> UMLL;
typedef unordered_map<PLL, int, h_pair> UMPI;
typedef unordered_map<PLL, ll, h_pair> UMPL;

int ar[10*MV], sze[MV];
bool isCrtd[MV];
ll arr[MV];
VI tupa;
vector<PII> G[MV], upa;

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

void dfs_sol2(int s, int p, int mv, int ht)
{
	upa.pb({mv, ht});
	tupa.pb(mv);
	for(auto u : G[s])
	{
		if((u.ff != p) && !isCrtd[u.ff])
		dfs_sol2(u.ff, s, mv + u.ss, ht + 1);	
	}
	return;
}

int dfs_sol1(int s, int compsz, int k)
{
	int mx = MOD;
	for(auto u : G[s])
	{
		if(isCrtd[u.ff])
		continue;
		dfs_sol2(u.ff, s, u.ss, 1);
		for(auto &&e : upa)
		{
			if(e.ff == k)
			mx = min(mx, e.ss);
			if(e.ff <= k)
			mx = min(mx, e.ss + ar[k-e.ff]);	
		}
		for(auto &&e : upa)
		{	
			if(e.ff <= k)
			ar[e.ff] = min(ar[e.ff], e.ss);
		}
		upa.clear();	
	}
	for(auto &&e : tupa)
	{	
		if(e <= k)
		ar[e] = MOD;
	}
	tupa.clear();
	return mx;	
}

int dfs_vis1(int s, int k)
{
	dfs_vis2(s, -1);
	PII centroid = cent_find(s, -1, s);
	int mx = dfs_sol1(centroid.ff, sze[s], k);
	isCrtd[centroid.ff] = 1;
	for(auto u : G[centroid.ff])
	{
		if(!isCrtd[u.ff])
		mx = min(mx, dfs_vis1(u.ff, k));	
	}	
	return mx;
}

int best_path(int N, int K, int H[][2], int L[])
{
	for(int i=0;i<N-1;i++)
	{
		G[H[i][0]+1].pb({H[i][1]+1, L[i]});
		G[H[i][1]+1].pb({H[i][0]+1, L[i]});
	}	
	for(int i=0;i<10*MV;i++)
	ar[i] = MOD;	
	int mx = dfs_vis1(1, K);
	if(mx == MOD)
	mx = -1;	
	return mx;
}