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

vector<PII> G[MV];
PPII E[MV];
int P[MV][LMV], sze[MV], lvl[MV], wt[MV], disc[MV], udsc[MV], head[MV], seg[4*MV];
int tx;

void dfs_vis1(int s, int p)
{
	P[s][0] = p;
	if(p != -1)
	lvl[s] = 1 + lvl[p];
	sze[s] = 1;
	for(auto u : G[s])
	{
		if(u.ff != p)
		{
			dfs_vis1(u.ff, s);
			sze[s] += sze[u.ff];
			wt[u.ff] = E[u.ss].ss;
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
		if(u.ff != p)
		chd.pb(u.ff);
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
			void update(int i, int s, int d, int x, int vx);
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
		seg[i] = wt[udsc[s]];
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
	return max(left, right);
}

void segtree::update(int i, int s, int d, int x, int vx)
{
	if(s == d)
	{
		wt[udsc[s]] = vx;
		seg[i] = vx;
		return;
	}
	int m = (s + d)/2;
	if(x <= m)
	update(2*i, s, m, x, vx);
	else update(2*i+1, m+1, d, x, vx);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;	
}

int segtree::query(int i, int s, int d, int qs, int qd)
{
	if(s > qd || d < qs)
	return 0;
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
	int n;
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int s,d,w;
		cin>>s>>d>>w;
		E[i] = {{s, d}, w};
		G[s].pb({d, i});
		G[d].pb({s, i});
	}	
	tx = 0;
	dfs_vis1(1, -1);
	iota(head, head+MV, 0);
	dfs_vis2(1, -1, 1);
	segtree D1;
	sparse D2;
	D1.build(1, 1, n);
	D2.build(n);
	while(1)
	{
		string s;
		cin>>s;
		if(s[0] == 'D')
		break;
		else
		{	
			int l,r;
			cin>>l>>r;
			if(s[0] == 'C')
			{
				E[l].ss = r;
				if(disc[E[l].ff.ff] > disc[E[l].ff.ss])
				D1.update(1, 1, n, disc[E[l].ff.ff], r);
				else D1.update(1, 1, n, disc[E[l].ff.ss], r);	
			}
			else
			{
				int lc = D2.LCA_find(l, r), mx = 0;
				while(head[lc] != head[l])
				{
					mx = max(mx, D1.query(1, 1, n, disc[head[l]], disc[l]));
					l = P[head[l]][0];
				}	
				if(l != lc)
				mx = max(mx, D1.query(1, 1, n, disc[lc]+1, disc[l]));	
				while(head[lc] != head[r])
				{
					mx = max(mx, D1.query(1, 1, n, disc[head[r]], disc[r]));
					r = P[head[r]][0];
				}	
				if(r != lc)
				mx = max(mx, D1.query(1, 1, n, disc[lc]+1, disc[r]));
				cout<<mx<<"\n";
			}
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
	cin>>T;

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