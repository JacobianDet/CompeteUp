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
int P[MV][LMV], sze[MV], lvl[MV], wt[MV], disc[MV], udsc[MV], head[MV], seg[4*MV];
int tx;

void dfs_vis1(int s, int p)
{
	P[s][0] = p;
	if(p != -1)
	lvl[s] = 1 + lvl[p];
	sze[s] = 1;
	wt[s] = 0;
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
			int merger(int left, int right);
			void update(int i, int s, int d, int x);
			int query(int i, int s, int d, int qs, int qd);
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
		seg[i] = 10000000;
		return;
	}
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

int segtree::merger(int left, int right)
{
	return min(left, right);
}

void segtree::update(int i, int s, int d, int x)
{
	if(s == d)
	{
		wt[udsc[s]] ^= 1;
		if(wt[udsc[s]])
		seg[i] = s;
		else seg[i] = 10000000;
		return;
	}
	int m = (s + d)/2;
	if(x <= m)
	update(2*i, s, m, x);
	else update(2*i+1, m+1, d, x);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;	
}

int segtree::query(int i, int s, int d, int qs, int qd)
{
	if(s > qd || d < qs)
	return 10000000;
	else if(qs <= s && d <= qd)
	return seg[i];
	int m = (s + d)/2;
	int p1 = query(2*i, s, m, qs, qd);
	int p2 = query(2*i+1, m+1, d, qs, qd);
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
	memset(wt, 0, sizeof(wt));
	memset(lvl, 0, sizeof(lvl));
	memset(disc, 0, sizeof(disc));
	memset(udsc, 0, sizeof(udsc));
	memset(sze, 0, sizeof(sze));
	int n,q;
	cin>>n>>q;
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
	while(q--)
	{
		int ty,x;
		cin>>ty>>x;
		if(!ty)
		D1.update(1, 1, n, disc[x]);
		else
		{
			int mx = 10000000;
			while(head[1] != head[x])
			{
				mx = min(mx, D1.query(1, 1, n, disc[head[x]], disc[x]));
				x = P[x][0];
			}
			mx = min(mx, D1.query(1, 1, n, disc[1], disc[x]));
			if(mx == 10000000)
			mx = -1;
			else mx = udsc[mx];
			cout<<mx<<"\n";	
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