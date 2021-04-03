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

int ar[MV], sto[MV], sze[MV], dia[MV], big[MV], lvl[MV], memo[(1<<22)];
vector<PII> G[MV];

void dfs_vis1(int s, int p)
{
	sze[s] = 1;
	lvl[s] = 0;
	if(p != -1)
	lvl[s] = 1 + lvl[p];	
	for(auto u : G[s])
	{
		if(u.ff != p)
		{
			sto[u.ff] = (sto[s] ^ (1<<u.ss));
			dfs_vis1(u.ff, s);
			sze[s] += sze[u.ff];
		}	
	}	
	return;	
}

void dfs_vis3(int s, int p, int rt)
{
	int uy = sto[s];
	for(int i=0;i<=22;i++)
	{
		if(i < 22)
		{
			int yt = (1<<i);
			yt ^= uy;
			dia[rt] = max(dia[rt], lvl[s] + memo[yt] - 2*lvl[rt]);
		}
		else
		{
			int yt = 0;
			yt ^= uy;
			dia[rt] = max(dia[rt], lvl[s] + memo[yt] - 2*lvl[rt]);
		}	
	}	
	for(auto u : G[s])
	{
		if((u.ff != p) && !big[u.ff])
		dfs_vis3(u.ff, s, rt);	
	}	
	return;
}

void dfs_vis4(int s, int p, int x)
{
	if(x == 1)
	memo[sto[s]] = max(memo[sto[s]], lvl[s]);
	else memo[sto[s]] = -MOD;
	for(auto u : G[s])
	{
		if((u.ff != p) && !big[u.ff])
		dfs_vis4(u.ff, s, x);	
	}	
	return;
}

void dfs_vis2(int s, int p, int keep)
{
	int hsz = 0, hed = 0;
	for(auto u : G[s])
	{
		if(u.ff != p)
		{
			if(sze[u.ff] > hsz)
			{
				hsz = sze[u.ff];
				hed = u.ff;
			}	
		}	
	}
	for(auto u : G[s])
	{
		if((u.ff != p) && (u.ff != hed))
		{	
			dfs_vis2(u.ff, s, 0);
			dia[s] = max(dia[s], dia[u.ff]);
		}		
	}	
	if(hed)
	{	
		dfs_vis2(hed, s, 1);
		dia[s] = max(dia[s], dia[hed]);
		big[hed] = 1;
	}	
	for(auto u : G[s])
	{
		if((u.ff != p) && !big[u.ff])
		{	
			dfs_vis3(u.ff, s, s);
			dfs_vis4(u.ff, s, 1);
		}		
	}
	int uy = 0;
	for(int i=0;i<=22;i++)
	{
		if(i < 22)
		{
			int yt = (1<<i);
			yt ^= (uy ^ sto[s]);
			dia[s] = max(dia[s], memo[yt] - lvl[s]);
		}
		else
		{
			int yt = 0;
			yt ^= (uy ^ sto[s]);
			dia[s] = max(dia[s], memo[yt] - lvl[s]);
		}	
	}
	memo[sto[s]] = max(memo[sto[s]], lvl[s]);	
	if(hed)
	big[hed] = 0;
	if(!keep)
	dfs_vis4(s, p, -1);
	return;	
}

void solve(int T)
{
	for(int i=0;i<(1<<22);i++)
	memo[i] = -MOD;	
	int n;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int p;
		char c;
		cin>>p>>c;
		G[i+1].pb({p, c-'a'});
		G[p].pb({i+1, c-'a'});
	}	
	dfs_vis1(1, -1);
	dfs_vis2(1, -1, 0);
	for(int i=1;i<=n;i++)
	cout<<dia[i]<<" \n"[i == n];
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