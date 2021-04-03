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
ll arr[MV];
PLL edg[MV];
vector<PII> G[MV];

int dfs_visit(int s, int p)
{
	bool chd = 1;
	int af = 0;
	for(auto u : G[s])
	{
		if(u.ff != p)
		{
			ar[u.ss] = 0;
			chd = 0;
			ar[u.ss] += dfs_visit(u.ff, s);
			af += ar[u.ss];
		}
	}
	if(chd)
	af = 1;
	return af;	
}

void solve(int T)
{
	int n;
	ll sf;
	cin>>n>>sf;
	for(int i=0;i<n-1;i++)
	{
		int s,d,c;
		ll w;
		cin>>s>>d>>w>>c;
		G[s].pb({d, i});
		G[d].pb({s, i});
		edg[i] = {w, c};
	}	
	int uy = dfs_visit(1, -1);
	VL v1, v2;
	set<PLL> S1, S2;
	ll ct1 = 0, ct2 = 0;
	for(int i=0;i<n-1;i++)
	{
		if(edg[i].ss == 1)
		{
			ct1 += edg[i].ff * (1LL*ar[i]);
			S1.ins({-(edg[i].ff - edg[i].ff/2) * (1LL*ar[i]), i});
			edg[i].ff /= 2;
		}
		else
		{
			ct2 += edg[i].ff * (1LL*ar[i]);
			S2.ins({-(edg[i].ff - edg[i].ff/2) * (1LL*ar[i]), i});
			edg[i].ff /= 2;	
		}
	}
	v1.pb(ct1);
	v2.pb(ct2);
	while(ct1 > 0)
	{
		PLL px = *S1.begin();
		S1.erase(S1.begin());
		ct1 += px.ff;
		v1.pb(ct1);
		px.ff = -(edg[px.ss].ff - edg[px.ss].ff/2) * (1LL*ar[px.ss]);
		edg[px.ss].ff /= 2;
		S1.ins(px);
	}
	while(ct2 > 0)
	{
		PLL px = *S2.begin();
		S2.erase(S2.begin());
		ct2 += px.ff;
		v2.pb(ct2);
		px.ff = -(edg[px.ss].ff - edg[px.ss].ff/2) * (1LL*ar[px.ss]);
		edg[px.ss].ff /= 2;	
		S2.ins(px);	
	}
	ll mz = INF;
	int p = sz(v2) - 1;
	for(int i=0;i<sz(v1);i++)
	{
		while((p > 0) && (v1[i] + v2[p-1] <= sf))
		p--;
		if(v1[i] + v2[p] <= sf)
		mz = min(mz, i + 2LL*p);	
	}
	cout<<mz<<"\n";
	for(int i=1;i<=n;i++)
	G[i].clear();
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