#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define INF (1LL<<59)
#define MV 200001
#define LMV 21
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define emp emplace
#define whoami(x) cerr<<#x<<" "<<x<<"\n";
#define mp make_pair
#define ins insert
#define sz size

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
ll arr[MV], in[2][MV], out[2][MV], res[2][MV];
VI G[MV];

void dfs_vis1(int s, int p, int m)
{
	in[0][s] = 1;
	in[1][s] = 1;
	for(auto u : G[s])
	{
		if(u != p)
		{
			dfs_vis1(u, s, m);
			in[0][s] = ((in[0][s]%m) * (((in[0][u]%m) + (1%m))%m))%m;
			in[1][s] = ((in[1][s]%m) + (((in[0][u]%m) + (in[1][u]%m))%m))%m;
		}
	}
	return;	
}

void dfs_vis2(int s, int p, int m)
{
	res[0][s] = ((in[0][s]%m) * (((out[0][s]%m) + (1%m))%m))%m;
	res[1][s] = ((in[1][s]%m) + (((out[0][s]%m) + (out[1][s]%m))%m))%m;
	VL prefm, suffm, chd;
	for(auto u : G[s])
	{
		if(u != p)
		chd.pb(u);	
	}
	ll pf = 1, ts = 0;
	for(auto u : chd)
	{
		prefm.pb(pf);
		ts = ((ts%m) + (((in[0][u]%m) + (in[1][u]%m))%m))%m;
		pf = ((pf%m) * (((in[0][u]%m) + (1%m))%m))%m;
	}
	pf = 1;
	for(int i=(int)chd.sz()-1;i>=0;i--)
	{
		suffm.pb(pf);
		pf = ((pf%m) * (((in[0][chd[i]]%m) + (1%m))%m))%m;
	}	
	pf = ((out[0][s]%m) + (1%m))%m;
	ts = ((ts%m) + (((out[0][s]%m) + (out[1][s]%m))%m))%m;
	reverse(begin(suffm), end(suffm));
	for(int i=0;i<(int)chd.sz();i++)
	{
		out[0][chd[i]] = ((((prefm[i]%m) * (suffm[i]%m))%m) * (pf%m))%m;
		out[1][chd[i]] = ((ts%m) - (((in[0][chd[i]]%m) + (in[1][chd[i]]%m))%m) + m)%m;	
		dfs_vis2(chd[i], s, m);
	}
	return;	
}

void solve(int T)
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}	
	dfs_vis1(1, -1, m);
	out[0][1] = 0;
	out[1][1] = 0;
	dfs_vis2(1, -1, m);
	for(int i=1;i<=n;i++)
	cout<<res[0][i]<<"\n";
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