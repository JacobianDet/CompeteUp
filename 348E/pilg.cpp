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

int ar[MV], P[MV][LMV], sze[MV], lvl[MV], head[MV], disc[MV], udsc[MV];
ll seg[4*MV], lazy[4*MV];
ll arr[MV];
PII in[MV], out[MV], res[MV];
vector<PII> G[MV];
int tx;

class segtree
{
	public: void build(int i, int s, int d);
			ll merger(ll left, ll right);
			void update(int i, int s, int d, int qs, int qd, int vx);
			ll query(int i, int s, int d, int qs, int qd);
};

class sparse
{
	public: void build(int n);
			int LCA_find(int p, int q);
};

PII dfs_vis1(int s, int p)
{
	PII cfd = {0, 0};
	for(auto u : G[s])
	{
		if(u.ff != p)
		{
			PII px = dfs_vis1(u.ff, s);
			if((px.ff > 0) || ((px.ff == 0) && ar[u.ff]))
			px.ff += u.ss;	
			if(cfd.ff > px.ff)
			continue;
			else if(cfd.ff < px.ff)
			cfd = px;
			else cfd.ss = s;	
		}
	}
	if(cfd.ff == 0)
	cfd.ss = s;	
	in[s] = cfd;
	return cfd;
}

void dfs_vis2(int s, int p)
{
	if(in[s].ff == out[s].ff)
	res[s] = {in[s].ff, s};
	else if(in[s].ff < out[s].ff)
	res[s] = out[s];
	else res[s] = in[s];	
	vector<PII> chd;
	chd.pb(out[s]);
	for(auto u : G[s])
	{
		if(u.ff != p)
		{	
			if((in[u.ff].ff > 0) || ((in[u.ff].ff == 0) && ar[u.ff]))
			chd.pb({in[u.ff].ff + u.ss, in[u.ff].ss});
			else chd.pb(in[u.ff]);
		}		
	}
	sort(begin(chd), end(chd), [](PII A, PII B){ return (A.ff > B.ff); });
	for(auto u : G[s])
	{
		if(u.ff != p)
		{
			int mf = min(sz(chd), 3);
			int mht = 0;
			for(int i=0;i<mf;i++)
			{
				if(chd[i].ss == in[u.ff].ss)
				continue;
				else
				{
					mht = chd[i].ff;
					break;
				}		
			}
			int ct = 0;
			for(int i=0;i<mf;i++)
			{
				if(chd[i].ss == in[u.ff].ss)
				continue;
				else if(mht == chd[i].ff)
				{
					out[u.ff] = chd[i];
					ct++;
				}	
			}	
			if((ct > 1) || (!out[u.ff].ff))
 			out[u.ff].ss = s;
			if((out[u.ff].ff > 0) || ((out[u.ff].ff == 0) && ar[s]))
			out[u.ff].ff += u.ss;
			dfs_vis2(u.ff, s);	
		}	
	}
	return;	
}

void dfs_vis3(int s, int p)
{
	P[s][0] = p;
	lvl[s] = 0;
	if(p != -1)
	lvl[s] = 1 + lvl[p];
	sze[s] = 1;
	for(auto u : G[s])
	{
		if(u.ff != p)
		{	
			dfs_vis3(u.ff, s);
			sze[s] += sze[u.ff];
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
		if(u.ff != p)
		chd.pb(u.ff);
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

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		seg[i] = 0;
		lazy[i] = 0;
		return;
	}	
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	lazy[i] = 0;
	return;
}

ll segtree::merger(ll left, ll right)
{
	return (left + right);
}

void segtree::update(int i, int s, int d, int qs, int qd, int vx)
{
	if(lazy[i])
	{
		seg[i] += (1LL*d-s+1) * lazy[i];
		if(s < d)
		{
			lazy[2*i] += lazy[i];
			lazy[2*i+1] += lazy[i];
		}	
		lazy[i] = 0;
	}	
	if(s > qd || d < qs)
	return;
	else if(qs <= s && d <= qd)
	{
		seg[i] += (1LL*d-s+1) * vx;
		if(s < d)
		{
			lazy[2*i] += vx;
			lazy[2*i+1] += vx;
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
		seg[i] += (1LL*d-s+1) * lazy[i];
		if(s < d)
		{
			lazy[2*i] += lazy[i];
			lazy[2*i+1] += lazy[i];
		}	
		lazy[i] = 0;
	}	
	if(s > qd || d < qs)
	return 0;
	else if(qs <= s && d <= qd)
	return seg[i];
	int m = (s + d)/2;
	ll p1 = query(2*i, s, m, qs, qd);
	ll p2 = query(2*i+1, m+1, d, qs, qd);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return merger(p1, p2); 
}

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
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int s;
		cin>>s;
		ar[s] = 1;
	}	
	for(int i=0;i<n-1;i++)
	{
		int s,d,w;
		cin>>s>>d>>w;
		G[s].pb({d, w});
		G[d].pb({s, w});
	}	
	in[1] = dfs_vis1(1, -1);
	out[1] = {0, 1};
	dfs_vis2(1, -1);
	dfs_vis3(1, -1);
	dfs_vis4(1, -1, 1);
	tx = 0;
	segtree D1;
	sparse D2;
	D1.build(1, 1, n);
	D2.build(n);
	for(int i=1;i<=n;i++)
	{
		if(ar[i])
		{
			int l = i;
			int r = res[i].ss;
			int lc = D2.LCA_find(l, r);
			// whoami(l, r, lc);
			while(head[lc] != head[l])
			{	
				D1.update(1, 1, n, disc[head[l]], disc[l], 1);
				l = P[head[l]][0];
			}
			if(l != lc)
			D1.update(1, 1, n, disc[lc] + 1, disc[l], 1);
			while(head[lc] != head[r])
			{	
				D1.update(1, 1, n, disc[head[r]], disc[r], 1);
				r = P[head[r]][0];
			}
			if(r != lc)
			D1.update(1, 1, n, disc[lc] + 1, disc[r], 1);
			D1.update(1, 1, n, disc[lc], disc[lc], 1);
		}
	}	
	int mv = 0, ct = 0;
	for(int i=1;i<=n;i++)
	{
		if(!ar[i])
		{
			int zz = D1.query(1, 1, n, disc[i], disc[i]);
			if(mv < zz)
			{
				ct = 1;
				mv = zz;
			}	
			else if(mv == zz)
			ct++;
		}	
	}
	cout<<mv<<" "<<ct<<"\n";
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