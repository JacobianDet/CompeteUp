#include <bits/stdc++.h>
using namespace std;
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
typedef map<ll, ll> MLL;
typedef map<PII, int> MPII;
typedef map<PLL, ll> MPLL;
typedef set<int> SI;
typedef set<ll> SL;

int ar[MV];
ll arr[MV];

VI G[MV];
int P[MV][LMV], sze[MV], lvl[MV], wt[MV], disc[MV], udsc[MV], head[MV];
int tx;

struct gss
{
	ll pref,suff,mv,tot;
}seg[4*MV];

PLL lazy[4*MV];

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

class segtree
{
	public: void build(int i, int s, int d);
			gss merger(gss left, gss right);
			void update(int i, int s, int d, int qs, int qd, ll x);
			gss query(int i, int s, int d, int qs, int qd);
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
		seg[i] = {((arr[udsc[s]] >= 0) ? arr[udsc[s]] : 0), ((arr[udsc[s]] >= 0) ? arr[udsc[s]] : 0), ((arr[udsc[s]] >= 0) ? arr[udsc[s]] : 0), arr[udsc[s]]};
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

gss segtree::merger(gss left, gss right)
{
	gss res;
	res.pref = max(left.pref, left.tot + right.pref);
	res.suff = max(right.suff, right.tot + left.suff);
	res.tot = left.tot + right.tot;
	res.mv = max(max(left.mv, right.mv), max(left.suff + right.pref, max(res.pref, res.suff)));
	return res;
}

void segtree::update(int i, int s, int d, int qs, int qd, ll x)
{
	if(lazy[i].ff)
	{
		seg[i] = {((lazy[i].ss >= 0) ? (d-s+1)*lazy[i].ss : 0), ((lazy[i].ss >= 0) ? (d-s+1)*lazy[i].ss : 0), ((lazy[i].ss >= 0) ? (d-s+1)*lazy[i].ss : 0), (d-s+1)*lazy[i].ss};
		if(s < d)
		{
			lazy[2*i] = lazy[i];
			lazy[2*i+1] = lazy[i];
		}
		lazy[i] = {0, 0};
	}
	if(s > qd || d < qs)
	return;	
	else if(qs <= s && d <= qd)
	{
		seg[i] = {((x >= 0) ? (d-s+1)*x : 0), ((x >= 0) ? (d-s+1)*x : 0), ((x >= 0) ? (d-s+1)*x : 0), (d-s+1)*x};
		if(s < d)
		{
			lazy[2*i] = {1, x};
			lazy[2*i+1] = {1, x};
		}
		return;
	}	
	int m = (s + d)/2;
	update(2*i, s, m, qs, qd, x);
	update(2*i+1, m+1, d, qs, qd, x);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;	
}

gss segtree::query(int i, int s, int d, int qs, int qd)
{
	if(lazy[i].ff)
	{
		seg[i] = {((lazy[i].ss >= 0) ? (d-s+1)*lazy[i].ss : 0), ((lazy[i].ss >= 0) ? (d-s+1)*lazy[i].ss : 0), ((lazy[i].ss >= 0) ? (d-s+1)*lazy[i].ss : 0), (d-s+1)*lazy[i].ss};
		if(s < d)
		{
			lazy[2*i] = lazy[i];
			lazy[2*i+1] = lazy[i];
		}
		lazy[i] = {0, 0};
	}
	if(s > qd || d < qs)
	return {0, 0, 0, 0};
	else if(qs <= s && d <= qd)
	return seg[i];
	int m = (s + d)/2;
	gss p1 = query(2*i, s, m, qs, qd);
	gss p2 = query(2*i+1, m+1, d, qs, qd);
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
	memset(P, -1, sizeof(P));
	memset(arr, 0, sizeof(wt));
	memset(lvl, 0, sizeof(lvl));
	memset(disc, 0, sizeof(disc));
	memset(udsc, 0, sizeof(udsc));
	memset(sze, 0, sizeof(sze));
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>arr[i];	
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}	
	tx = 0;
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
		if(--ty)
		{
			int l,r;
			ll vx;
			cin>>l>>r>>vx;
			int lc = D2.LCA_find(l, r);
			while(head[lc] != head[l])
			{
				D1.update(1, 1, n, disc[head[l]], disc[l], vx);
				l = P[head[l]][0];
			}
			D1.update(1, 1, n, disc[lc], disc[l], vx);
			while(head[lc] != head[r])
			{
				D1.update(1, 1, n, disc[head[r]], disc[r], vx);
				r = P[head[r]][0];
			}
			if(lc != r)
			D1.update(1, 1, n, disc[lc]+1, disc[r], vx);	
		}
		else
		{
			int l,r;
			cin>>l>>r;
			int lc = D2.LCA_find(l, r);
			vector<gss> res, tx;
			while(head[lc] != head[l])
			{
				gss gz = D1.query(1, 1, n, disc[head[l]], disc[l]);
				gz.pref ^= gz.suff;
				gz.suff = gz.pref ^ gz.suff;
				gz.pref ^= gz.suff;
				res.pb(gz);
				l = P[head[l]][0];
			}
			gss gz = D1.query(1, 1, n, disc[lc], disc[l]);
			gz.pref ^= gz.suff;
			gz.suff = gz.pref ^ gz.suff;
			gz.pref ^= gz.suff;
			res.pb(gz);
			while(head[lc] != head[r])
			{
				tx.pb(D1.query(1, 1, n, disc[head[r]], disc[r]));
				r = P[head[r]][0];
			}
			if(lc != r)
			tx.pb(D1.query(1, 1, n, disc[lc]+1, disc[r]));
			reverse(tx.begin(), tx.end());
			for(auto u : tx)
			res.pb(u);
			gss ans = {0, 0, 0, 0};
			for(auto u : res)
			{
				ll p = 0, s = 0;
				p = max(ans.pref, ans.tot + u.pref);
				s = max(u.suff, u.tot + ans.suff);
				ans.tot += u.tot;
				ans.mv = max(max(ans.mv, u.mv), max(ans.suff + u.pref, max(p, s)));
				ans.pref = p;
				ans.suff = s; 
			}
			cout<<ans.mv<<"\n";	
		}
	}
	for(int i=1;i<=n;i++)
	G[i].clear();	
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