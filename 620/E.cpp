#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define MOD 1000000007
#define INF (1LL<<57)
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
void SETF() {cout.ios_base::setf(ios_base::fixed);}
void UNSETF() {cout.ios_base::unsetf(ios_base::fixed);}

typedef long long ll;
typedef long double ld;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef pair<PII, int> PPII;
typedef pair<PLL, ll> PPLL;
typedef map<int, int> MII;

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
//ordered_set = order_by_key(.)
//ordered_set = find_by_order(.)
typedef ordered_set<int> OSI;
typedef ordered_set<ll> OSL;
typedef ordered_multiset<int> MOSI;
typedef ordered_multiset<ll> MOSL;
typedef unordered_map<ll, int, h_llint> UMLI;
typedef unordered_map<ll, ll, h_llint> UMLL;
typedef unordered_map<PLL, int, h_pair> UMPI;
typedef unordered_map<PLL, ll, h_pair> UMPL;

int ar[MV], P[MV][LMV], lvl[MV], disc[MV], sze[MV];
ll arr[MV];
VI G[MV];
int tx;

class sparse
{
	public: void ST_build(int n);
			int LCA_find(int p, int q);
};

void sparse::ST_build(int n)
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
}

int sparse::LCA_find(int p, int q)
{
	if(lvl[p] < lvl[q])
	swap(p, q);
	int lx = 0;
	for(lx=1;(1<<lx)<=lvl[p];lx++);
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

void dfs_visit(int s, int p)
{
	tx++;
	disc[s] = tx;
	P[s][0] = p;
	lvl[s] = 0;
	sze[s] = 1;
	if(p != -1)
	lvl[s] = 1 + lvl[p];
	for(auto u : G[s])
	{
		if(u != p)
		{
			dfs_visit(u, s);
			sze[s] += sze[u];
		}		
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
	tx = 0;
	dfs_visit(1, -1);
	sparse D;
	D.ST_build(n);
	int q;
	cin>>q;
	while(q--)
	{
		int x,y,a,b,k;
		cin>>x>>y>>a>>b>>k;
		int lc1 = D.LCA_find(a,b);
		// if((disc[lc] <= disc[x]) && (disc[x] < disc[lc] + sze[lc]) && (disc[lc] <= disc[y]) && (disc[y] < disc[lc] + sze[lc]))
		int m1 = lvl[a] + lvl[b] - 2*lvl[lc1];
		int lc2 = D.LCA_find(a, x), lc3 = D.LCA_find(b, y);
		int m2 = (lvl[a] + lvl[x] - 2*lvl[lc2]) + 1 + (lvl[y] + lvl[b] - 2*lvl[lc3]);
		int lc4 = D.LCA_find(b, x), lc5 = D.LCA_find(a, y);
		int m3 = (lvl[a] + lvl[y] - 2*lvl[lc5]) + 1 + (lvl[x] + lvl[b] - 2*lvl[lc4]);
		if(((k >= m1) && !((k ^ m1) & 1)) || ((k >= m2) && !((k ^ m2) & 1)) || ((k >= m3) && !((k ^ m3) & 1)))
		cout<<"YES\n";
		else cout<<"NO\n";	
	}
	return;
}

int main(void)
{
	FLASH();
	int T;
	T = 1;

#ifndef ONLINE_JUDGE
	time_t time_t1, time_t2;
	time_t1 = clock();
#endif

	while(T--)
	solve(T);

#ifndef ONLINE_JUDGE
	time_t2 = clock();
	SETF();
	cout<<"Time taken: "<<setprecision(7)<<(time_t2 - time_t1)/(double)CLOCKS_PER_SEC<<"\n";
	UNSETF();
#endif

	return 0;
}