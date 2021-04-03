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

int ar[MV], rc[MV];
ll arr[MV];
VI G[MV], tgt(3);
vector<PPII> xfd;
int memo[5001][5001];

bool dfs_vis1(int s, int cl)
{
	ar[s] = cl;
	bool ok = 1;
	for(auto &&u : G[s])
	{
		if(!ar[u])
		ok &= dfs_vis1(u, ((cl == 1) ? 2 : 1));
		else if(ar[u] == cl)
		ok = 0;	
	}	
	return ok;
}

PII dfs_vis2(int s, int cl)
{
	ar[s] = cl;
	int c1 = 0, c2 = 0;
	for(auto &&u : G[s])
	{
		if(!ar[u])
		{
			PII yt = dfs_vis2(u, ((cl == 1) ? 2 : 1));
			c1 += yt.ff;
			c2 += yt.ss;
		}	
	}
	if(cl == 1)
	c1++;
	else c2++;
	return {c1, c2};	
}

void dfs_vis3(int s, int cl)
{
	ar[s] = cl;
	if(cl == 2)
	{
		rc[s] = 2;
		tgt[1]--;
	}	
	else
	{
		if(tgt[0] > 0)
		{
			rc[s] = 1;
			tgt[0]--;
		}	
		else 
		{
			rc[s] = 3;
			tgt[2]--;
		}
	}
	for(auto &&u : G[s])
	{
		if(!ar[u])
		dfs_vis3(u, ((cl == 1) ? 2 : 1));	
	}
	return;
}

int xd(int ix, int t2, int n)
{
	if(ix == (int)xfd.sz())
	return 1;
	if(memo[ix][t2] != -1)
	return memo[ix][t2];
	int ans = 0;
	if((t2 >= xfd[ix].ff.ff) && (n-((ix > 0) ? ar[ix-1] : 0)-t2 >= xfd[ix].ff.ss) && xd(ix+1, t2-xfd[ix].ff.ff, n))
	ans = 2;	
	if((t2 >= xfd[ix].ff.ss) && (n-((ix > 0) ? ar[ix-1] : 0)-t2 >= xfd[ix].ff.ff) && xd(ix+1, t2-xfd[ix].ff.ss, n))
	ans = 1;	
	memo[ix][t2] = ans;
	return ans;
}

void solve(int T)
{
	int n,m;
	cin>>n>>m;
	for(auto &&u : tgt)
	cin>>u;
	for(int i=0;i<m;i++)
	{
		int s,d;
		cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}	
	bool ok = 1;
	for(int i=1;i<=n;i++)
	{
		if(!ar[i])
		ok &= dfs_vis1(i, 1);
	}
	if(!ok)
	cout<<"NO\n";
	else
	{
		ok = 1;
		memset(memo, -1, sizeof(memo));
		memset(ar, 0, sizeof(ar));
		for(int i=1;i<=n;i++)
		{
			if(!ar[i])
			xfd.pb({dfs_vis2(i, 1), i});
		}
		memset(ar, 0, sizeof(ar));
		for(int i=0;i<(int)xfd.sz();i++)
		{	
			ar[i] = xfd[i].ff.ff + xfd[i].ff.ss;
			if(i > 0)
			ar[i] += ar[i-1];
		}		
		ok = xd(0, tgt[1], n);
		if(!ok)
		cout<<"NO\n";
		else
		{	
			cout<<"YES\n";
			memset(ar, 0, sizeof(ar));
			for(int i=0;i<(int)xfd.sz();i++)
			dfs_vis3(xfd[i].ss, memo[i][tgt[1]]);
			for(int i=1;i<=n;i++)
			cout<<rc[i];
			cout<<"\n";
		}		
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