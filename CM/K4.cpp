#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
ll arr[MV], seg[4*MV], lazy[4*MV];

VI G[MV];
int P[MV][LMV], sze[MV], lvl[MV], wt[MV], disc[MV], udsc[MV], head[MV];
int tx;

void dfs_vis1(int s, int p)
{
	P[s][0] = p;
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

void dfs_vis2(int s, int p, int chh)
{
	head[s] = chh;
	tx++;
	disc[s] = tx;
	udsc[tx] = s;
	VI chd;
	for(auto u : G[s])
	{
		if(u != p)
		chd.pb(u);
	}
	sort(chd.begin(), chd.end(), [](int A, int B){ return (sze[A] > sze[B]); });
	bool ok = 1;
	for(auto u : chd)
	{
		if(ok)
		{
			dfs_vis2(u, s, chh);
			ok ^= 1;
		}	
		else dfs_vis2(u, s, u);
	}
	return;
}

class sparse
{
	public: void build(int n);
			int LCA_find(int p, int q);
};

void sparse::build(int n)
{
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(P[i][j-1] != -1)
			P[i][j] = P[P[i][j-1]][j-1];
		}	
	}
	return;
}

int sparse::LCA_find(int p, int q)
{
	if(lvl[p] < lvl[q])
	{
		int tp = p;
		p = q;
		q = tp;
	}
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

class segtree
{
	public: void build(int i, int s, int d);
			ll merger(ll left, ll right);
			void update(int i, int s, int d, int qs, int qd, ll vx);
			ll query(int i, int s, int d, int qs, int qd);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		seg[i] = arr[udsc[s]];
		lazy[i] = 0;
		return;
	}	
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	lazy[i] = 0;
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

ll segtree::merger(ll left, ll right)
{
	return left ^ right;
}

void segtree::update(int i, int s, int d, int qs, int qd, ll vx)
{
	if(lazy[i])
	{
		if((d - s + 1) & 1)
		seg[i] ^= lazy[i];
		if(s < d)
		{
			lazy[2*i] ^= lazy[i];
			lazy[2*i+1] ^= lazy[i];
		}	
		lazy[i] = 0;
	}
	if(s > qd || d < qs)
	return;
	else if(qs <= s && d <= qd)
	{
		if((d - s + 1) & 1)
		seg[i] ^= vx;
		if(s < d)
		{
			lazy[2*i] ^= vx;
			lazy[2*i+1] ^= vx;
		}	
		return;
	}	
	int m = (s + d)/2;
	update(2*i, s, m, qs, qd, vx);
	update(2*i+1, m+1, d, qs, qd, vx);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

ll segtree::query(int i, int s, int d, int qs, int qd)
{
	if(lazy[i])
	{
		if((d - s + 1) & 1)
		seg[i] ^= lazy[i];
		if(s < d)
		{
			lazy[2*i] ^= lazy[i];
			lazy[2*i+1] ^= lazy[i];
		}	
		lazy[i] = 0;
	}
	if(s > qd || d < qs)
	return 0LL;
	else if(qs <= s && d <= qd)
	return seg[i];
	int m = (s + d)/2;
	ll p1 = query(2*i, s, m, qs, qd);
	ll p2 = query(2*i+1, m+1, d, qs, qd);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return merger(p1, p2);	
}

void solve(int T)
{
	int n;
	cin>>n;
	tx = 0;
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}
	for(int i=1;i<=n;i++)
	cin>>arr[i];
	dfs_vis1(1, -1);
	iota(head, head+MV, 0);
	dfs_vis2(1, -1, 1);
	segtree D1;
	sparse D2;
	D1.build(1, 1, n);
	D2.build(n);
	int q;
	cin>>q;
	while(q--)
	{
		int ty;
		cin>>ty;
		if(ty == 1)
		{
			int nx;
			ll vx;
			cin>>nx>>vx;
			D1.update(1, 1, n, disc[nx], disc[nx] + sze[nx] - 1, vx);
		}
		else
		{
			int x,y;
			cin>>x>>y;
			int lc = D2.LCA_find(x, y);
			ll res = 0;
			while(head[lc] != head[x])
			{
				res ^= D1.query(1, 1, n, disc[head[x]], disc[x]);
				x = P[head[x]][0];
			}
			res ^= D1.query(1, 1, n, disc[lc], disc[x]);
			while(head[lc] != head[y])
			{
				res ^= D1.query(1, 1, n, disc[head[y]], disc[y]);
				y = P[head[y]][0];
			}
			if(lc != y)
			res ^= D1.query(1, 1, n, disc[lc]+1, disc[y]);
			cout<<res<<"\n";
		}
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