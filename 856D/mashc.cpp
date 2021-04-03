#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define MV 300001
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

int ar[MV], P[MV][LMV], lvl[MV], dsc[MV], sze[MV], BIT[MV], res[MV], sm[MV];
ll arr[MV];
vector<PPII> edg;
VI G[MV], ES[MV];
int tx;

class sparse
{
	public: void build(int n);
			int LCA_find(int p, int q);
};

class fentree
{
	public: void update(int i, int val);
			int query(int i);
}F;

void sparse::build(int n)
{
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;i<=n;i++)
		{
			P[i][j] = -1;
			if(P[i][j-1] != -1)
			P[i][j] = P[P[i][j-1]][j-1];	
		}
	}
	return;	
}

int sparse::LCA_find(int p, int q)
{
	if(lvl[p] < lvl[q])
	swap(p, q);
	int lx = 0;
	for( ;(1<<lx)<=lvl[p];lx++);
	lx--;
	for(int i=lx;i>=0;i--)
	{
		if((lvl[p] - (1<<i)) >= lvl[q])
		p = P[p][i];	
	}
	if(p == q)
	return p;
	for(int i=lx;i>=0;i--)
	{
		if((P[p][i] != -1) && (P[p][i] != P[q][i]))
		{
			p = P[p][i];
			q = P[q][i];
		}	
	}
	return P[p][0];	
}

void fentree::update(int i, int val)
{
	for( ;i<MV;i+=(i & (-i)))
	BIT[i] += val;	
	return;
}

int fentree::query(int i)
{
	int ans = 0;
	for( ;i>0;i-=(i & (-i)))
	ans += BIT[i];
	return ans;	
}

void dfs_vis1(int s, int p)
{
	dsc[s] = ++tx;
	P[s][0] = p;
	lvl[s] = 0;
	if(p != -1)
	lvl[s] = 1 + lvl[p];
	sze[s] = 1;
	for(auto u : G[s])
	{
		if(u != p)
		{
			dfs_vis1(u, s);
			sze[s] += sze[u];
		}	
	}	
	return;
}

void dfs_vis2(int s, int p)
{
	int ans = 0;
	for(auto u : G[s])
	{
		if(u != p)
		{
			dfs_vis2(u, s);
			sm[s] += res[u];
		}	
	}
	res[s] = sm[s];
	for(auto u : ES[s])
	res[s] = max(res[s], F.query(dsc[edg[u].ff.ff]) + F.query(dsc[edg[u].ff.ss]) + sm[s] + edg[u].ss);
	F.update(dsc[s], sm[s] - res[s]);
	F.update(dsc[s] + sze[s], res[s] - sm[s]);
	return;
}

void solve(int T)
{
	tx = 0;
	int n,m;
	cin>>n>>m;
	for(int i=2;i<=n;i++)
	{
		int p;
		cin>>p;
		G[i].pb(p);
		G[p].pb(i);
	}	
	dfs_vis1(1, -1);
	sparse D;
	D.build(n);
	for(int i=0;i<m;i++)
	{
		int s,d,c;
		cin>>s>>d>>c;
		edg.pb({{s, d}, c});
		ES[D.LCA_find(s, d)].pb(i);
	}
	dfs_vis2(1, -1);
	cout<<res[1]<<"\n";
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