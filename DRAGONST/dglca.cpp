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

int ar[MV], rk[MV], lvl[MV], P[MV][LMV];
ll dx[MV][LMV];
PLL seg[4*MV], lazy[4*MV];
vector<PLL> G[MV], ptz;
vector<PPLL> edg;
PPLL prox[MV];

class segtree
{
	public: void build(int i, int s, int d);
			PLL merger(PLL left, PLL right);
			void update(int i, int s, int d, int qs, int qd, PLL mv);
			PLL query(int i, int s, int d, int qs, int qd);
};

class dsu
{
	public: int root(int x);
			bool find_union(int x, int y);
};

class sparse
{
	public: void build(int n);
			ll LCA_find(int p, int q);
};

void sparse::build(int n)
{
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;i<=n;i++)
		{
			P[i][j] = -1;
			dx[i][j] = 0;
			if(P[i][j-1] != -1)
			{	
				P[i][j] = P[P[i][j-1]][j-1];
				dx[i][j] = max(dx[i][j-1], dx[P[i][j-1]][j-1]);
			}	
		}	
	}
	return;
}

ll sparse::LCA_find(int p, int q)
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
	ll zf = 0;
	for(int i=lx;i>=0;i--)
	{
		if((lvl[p] - (1<<i)) >= lvl[q])
		{
			zf = max(zf, dx[p][i]);
			p = P[p][i];
		}	
	}	
	if(p == q)
	return zf;
	for(int i=lx;i>=0;i--)
	{
		if((P[p][i] != -1) && (P[p][i] != P[q][i]))
		{
			zf = max({zf, dx[p][i], dx[q][i]});
			p = P[p][i];
			q = P[q][i];
		}	
	}	
	zf = max({zf, dx[p][0], dx[q][0]});
	return zf;
}

int dsu::root(int x)
{
	return ((x == ar[x]) ? x : (ar[x] = root(ar[x])));
}

bool dsu::find_union(int x, int y)
{
	int rx = root(x);
	int ry = root(y);
	if(rx == ry)
	return 0;
	if(rk[rx] < rk[ry])
	swap(rx, ry);
	ar[ry] = rx;
	if(rk[rx] == rk[ry])
	rk[rx]++;
	return 1;	
}

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		seg[i] = {2LL*MOD, -1};
		lazy[i] = {2LL*MOD, -1};
		return;
	}
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	lazy[i] = {2LL*MOD, -1};
	return;
}

PLL segtree::merger(PLL left, PLL right)
{
	return min(left, right);
}

void segtree::update(int i, int s, int d, int qs, int qd, PLL mv)
{
	if(lazy[i].ff != 2LL*MOD)
	{
		seg[i] = ((seg[i].ff > lazy[i].ff) ? lazy[i] : seg[i]);
		if(s < d)
		{
			lazy[2*i] = ((lazy[2*i].ff > lazy[i].ff) ? lazy[i] : lazy[2*i]);
			lazy[2*i+1] = ((lazy[2*i+1].ff > lazy[i].ff) ? lazy[i] : lazy[2*i+1]);
		}
		lazy[i] = {2LL*MOD, -1};
	}	
	if(s > qd || d < qs)
	return;
	else if(qs <= s && d <= qd)
	{
		seg[i] = ((seg[i].ff > mv.ff) ? mv : seg[i]);
		if(s < d)
		{
			lazy[2*i] = ((lazy[2*i].ff > mv.ff) ? mv : lazy[2*i]);
			lazy[2*i+1] = ((lazy[2*i+1].ff > mv.ff) ? mv : lazy[2*i+1]);
		}
		return;
	}	
	int m = (s + d)/2;
	update(2*i, s, m, qs, qd, mv);
	update(2*i+1, m+1, d, qs, qd, mv);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

PLL segtree::query(int i, int s, int d, int qs, int qd)
{
	if(lazy[i].ff != 2LL*MOD)
	{
		seg[i] = ((seg[i].ff > lazy[i].ff) ? lazy[i] : seg[i]);
		if(s < d)
		{
			lazy[2*i] = ((lazy[2*i].ff > lazy[i].ff) ? lazy[i] : lazy[2*i]);
			lazy[2*i+1] = ((lazy[2*i+1].ff > lazy[i].ff) ? lazy[i] : lazy[2*i+1]);
		}
		lazy[i] = {2LL*MOD, -1};
	}	
	if(s > qd || d < qs)
	return {2LL*MOD, -1};
	else if(qs <= s && d <= qd)
	return seg[i];	
	int m = (s + d)/2;
	PLL p1 = query(2*i, s, m, qs, qd);
	PLL p2 = query(2*i+1, m+1, d, qs, qd);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return merger(p1, p2);	
}

void fun(int n)
{
	sort(prox+1, prox+n+1, [](PPLL A, PPLL B){ return (A.ff.ss > B.ff.ss); });
	VL ytx;
	for(int i=1;i<=n;i++)
	{
		if(ytx.empty())
		ytx.pb(prox[i].ff.ss);
		else if(ytx.back() != prox[i].ff.ss)
		ytx.pb(prox[i].ff.ss);	
	}	
	segtree D;
	D.build(1, 1, sz(ytx));
	sort(prox+1, prox+n+1, [](PPLL A, PPLL B){ return (mp(A.ff.ff - A.ff.ss, A.ff.ss) > mp(B.ff.ff - B.ff.ss, B.ff.ss)); });
	for(int i=1;i<=n;i++)
	{
		int pos = 1 + (lower_bound(begin(ytx), end(ytx), prox[i].ff.ss, greater<ll>()) - begin(ytx));
		PLL cid = D.query(1, 1, sz(ytx), 1, pos);
		if(cid.ss != -1)
		{
			int ix = prox[i].ss - 1;
			int jx = cid.ss - 1;
			ll wt = max(ptz[ix].ff - ptz[jx].ff, ptz[jx].ff - ptz[ix].ff) + max(ptz[ix].ss - ptz[jx].ss, ptz[jx].ss - ptz[ix].ss);
			edg.pb({{prox[i].ss, cid.ss}, wt});
		}	
		D.update(1, 1, sz(ytx), pos, sz(ytx), {prox[i].ff.ff + prox[i].ff.ss, prox[i].ss});	
	}	
	return;
}

void dfs_visit(int s, int p)
{
	P[s][0] = p;
	lvl[s] = 0;
	if(p != -1)
	lvl[s] = 1 + lvl[p];
	for(auto u : G[s])
	{
		if(u.ff != p)
		{
			dx[u.ff][0] = u.ss;
			dfs_visit(u.ff, s);
		}
	}	
	return;
}

void solve(int T)
{
	int n;
	cin>>n;
	ptz.resize(n);
	for(auto &&u : ptz)
	cin>>u.ff>>u.ss;
	for(int i=1;i<=n;i++)
	prox[i] = {{ptz[i-1].ff, ptz[i-1].ss}, i};
	fun(n);
	for(int i=1;i<=n;i++)
	prox[i] = {{-ptz[i-1].ff, ptz[i-1].ss}, i};
	fun(n);	
	for(int i=1;i<=n;i++)
	prox[i] = {{ptz[i-1].ff, -ptz[i-1].ss}, i};
	fun(n);
	for(int i=1;i<=n;i++)
	prox[i] = {{-ptz[i-1].ff, -ptz[i-1].ss}, i};
	fun(n);
	for(int i=1;i<=n;i++)
	prox[i] = {{ptz[i-1].ss, ptz[i-1].ff}, i};
	fun(n);
	for(int i=1;i<=n;i++)
	prox[i] = {{-ptz[i-1].ss, ptz[i-1].ff}, i};
	fun(n);
	for(int i=1;i<=n;i++)
	prox[i] = {{ptz[i-1].ss, -ptz[i-1].ff}, i};
	fun(n);
	for(int i=1;i<=n;i++)
	prox[i] = {{-ptz[i-1].ss, -ptz[i-1].ff}, i};
	fun(n);
	sort(begin(edg), end(edg), [](PPLL A, PPLL B){ return (A.ss < B.ss); });
	for(int i=1;i<=n;i++)
	{
		ar[i] = i;
		rk[i] = 0;
	}	
	dsu Z;
	for(auto &&u : edg)
	{
		int s = u.ff.ff, d = u.ff.ss;
		if(Z.find_union(s, d))
		{
			G[s].pb({d, u.ss});
			G[d].pb({s, u.ss});
		}	
	}
	dx[1][0] = 0;
	dfs_visit(1, -1);
	sparse D;
	D.build(n);
	int q;
	cin>>q;
	while(q--)
	{
		int s,d;
		cin>>s>>d;
		ll rz = D.LCA_find(s, d);
		cout<<rz<<"\n";
	}
	for(int i=1;i<=n;i++)
	G[i].clear();
	edg.clear();	
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