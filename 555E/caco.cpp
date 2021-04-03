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

ll arr[MV];
vector<PII> edg;
VI brg, G[MV];
int P[MV][LMV], sze[MV], disc[MV], udsc[MV], head[MV], ar[MV], brc[MV], lvl[MV], cmp[MV];
int tx;
PLL seg[4*MV], lazy[4*MV];

void dfs_vis1(int s)
{
	for(auto u : G[s])
	{
		if(!lvl[u])
		{
			lvl[u] = 1 + lvl[s];
			dfs_vis1(u);
			brc[s] += brc[u];
		}	
		else if(lvl[u] > lvl[s])
		brc[s]--;
		else brc[s]++;	
	}
	brc[s]--;
	if((lvl[s] > 1) && (brc[s] == 0))
	brg.pb(s);
	return;
}

void dfs_vis2(int s, int x)
{
	ar[s] = x;
	for(auto u : G[s])
	{
		if(!ar[u] && (lvl[u] > lvl[s]))
		dfs_vis2(u, x);	
	}
	return;
}

void dfs_vis3(int s, int p, int x)
{
	cmp[s] = x;
	P[s][0] = p;
	if(p != -1)
	lvl[s] = 1 + lvl[p];
	sze[s] = 1;
	for(auto u : G[s])
	{
		if(u != p)
		{
			dfs_vis3(u, s, x);
			sze[s] += sze[u];
		}
	}
	return;
}

void dfs_vis4(int s, int p, int chh)
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
			dfs_vis4(u, s, chh);
			ok ^= 1;
		}	
		else dfs_vis4(u, s, u);
	}
	return;
}

class segtree
{
	public: void build(int i, int s, int d);
			PLL merger(PLL left, PLL right);
			void update(int i, int s, int d, int qs, int qd, int ty);
			PLL query(int i, int s, int d, int qs, int qd);
};

class sparse
{
	public: void build(int n);
			int LCA_find(int p, int q);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		seg[i] = {0, 0};
		lazy[i] = {0, 0};
		return;
	}
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	lazy[i] = {0, 0};
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

PLL segtree::merger(PLL left, PLL right)
{
	return {left.ff + right.ff, left.ss + right.ss};
}

void segtree::update(int i, int s, int d, int qs, int qd, int ty)
{
	if(lazy[i].ff || lazy[i].ss)
	{
		seg[i].ff += (d-s+1) * lazy[i].ff;
		seg[i].ss += (d-s+1) * lazy[i].ss;
		if(s < d)
		{
			lazy[2*i].ff += lazy[i].ff;
			lazy[2*i].ss += lazy[i].ss;
			lazy[2*i+1].ff += lazy[i].ff;
			lazy[2*i+1].ss += lazy[i].ss;
		}
		lazy[i] = {0, 0};
	}
	if(s > qd || d < qs)
	return;	
	else if(qs <= s && d <= qd)
	{
		if(!ty)
		seg[i].ff += (d-s+1);
		else seg[i].ss += (d-s+1);	
		if(s < d)
		{
			if(!ty)
			{
				lazy[2*i].ff++;
				lazy[2*i+1].ff++;
			}	
			else
			{
				lazy[2*i].ss++;
				lazy[2*i+1].ss++;
			}
		}
		return;
	}	
	int m = (s + d)/2;
	update(2*i, s, m, qs, qd, ty);
	update(2*i+1, m+1, d, qs, qd, ty);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;	
}

PLL segtree::query(int i, int s, int d, int qs, int qd)
{
	if(lazy[i].ff || lazy[i].ss)
	{
		seg[i].ff += (d-s+1) * lazy[i].ff;
		seg[i].ss += (d-s+1) * lazy[i].ss;
		if(s < d)
		{
			lazy[2*i].ff += lazy[i].ff;
			lazy[2*i].ss += lazy[i].ss;
			lazy[2*i+1].ff += lazy[i].ff;
			lazy[2*i+1].ss += lazy[i].ss;
		}
		lazy[i] = {0, 0};
	}
	if(s > qd || d < qs)
	return {0, 0};
	else if(qs <= s && d <= qd)
	return seg[i];
	int m = (s + d)/2;
	PLL p1 = query(2*i, s, m, qs, qd);
	PLL p2 = query(2*i+1, m+1, d, qs, qd);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return merger(p1, p2); 
}

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

void solve(int T)
{
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=0;i<m;i++)
	{
		int s,d;
		cin>>s>>d;
		edg.pb({s, d});
		G[s].pb(d);
		G[d].pb(s);
	}	
	for(int i=1;i<=n;i++)
	{
		if(!lvl[i])
		{	
			lvl[i] = 1;
			dfs_vis1(i);	
		}	
	}	
	int x = 0;
	for(auto u : brg)
	{
		if(!ar[u])
		{
			x++;
			dfs_vis2(u, x);
		}	
	}
	for(int i=1;i<=n;i++)
	{
		if(!ar[i])
		{
			x++;
			dfs_vis2(i, x);
		}
	}	
	for(int i=1;i<=n;i++)
	G[i].clear();
	for(auto u : edg)
	{
		int s = u.ff, d = u.ss;
		s = ar[s];
		d = ar[d];
		if(s == d)
		continue;
		G[s].pb(d);
		G[d].pb(s);
	}
	tx = 0;
	iota(head, head+MV, 0);
	memset(lvl, 0, sizeof(lvl));
	n = x;
	x = 0;
	for(int i=1;i<=n;i++)
	{
		if(!cmp[i])
		{
			x++;
			dfs_vis3(i, -1, x);
		}	
	}	
	for(int i=1;i<=n;i++)
	{
		if(!disc[i])
		dfs_vis4(i, -1, i);
	}	
	segtree D1;
	sparse D2;
	D1.build(1, 1, n);
	D2.build(n);
	bool ok = 1;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		l = ar[l];
		r = ar[r];	
		if(l == r)
		continue;
		if(cmp[l] != cmp[r])
		{
			ok = 0;
			continue;
		}	
		int lc = D2.LCA_find(l, r);
		// cout<<l<<" "<<r<<" "<<lc<<"\n";
		while(head[lc] != head[l])
		{
			D1.update(1, 1, n, disc[head[l]], disc[l], 1);
			l = P[head[l]][0];
		}
		if(disc[lc] < disc[l])
		D1.update(1, 1, n, disc[lc]+1, disc[l], 1);
		while(head[lc] != head[r])
		{
			D1.update(1, 1, n, disc[head[r]], disc[r], 0);
			r = P[head[r]][0];
		}
		if(disc[lc] < disc[r])
		D1.update(1, 1, n, disc[lc]+1, disc[r], 0);
	}
	for(int i=1;i<=n;i++)
	{
		PLL px = D1.query(1, 1, n, i, i);
		// cout<<px.ff<<" "<<px.ss<<"\n";
		if(px.ff && px.ss)
		ok = 0;	
	}
	cout<<(ok ? "Yes" : "No")<<"\n";
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