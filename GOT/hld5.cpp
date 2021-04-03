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
map<ll, VI> MX;

class sparse
{
	public: void build(int n);
			int LCA_find(int p, int q);
};

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
	int n,q;
	while(cin>>n>>q)
	{
		memset(P, -1, sizeof(P));
		memset(arr, 0, sizeof(wt));
		memset(lvl, 0, sizeof(lvl));
		memset(disc, 0, sizeof(disc));
		memset(udsc, 0, sizeof(udsc));
		memset(sze, 0, sizeof(sze));
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
		sparse D2;
		D2.build(n);
		for(int i=1;i<=n;i++)
		MX[arr[udsc[i]]].pb(i);	
		while(q--)
		{
			int l,r;
			ll v;
			cin>>l>>r>>v;
			int lc = D2.LCA_find(l, r);
			bool ok = 0;
			while(head[lc] != head[l])
			{
				int lv = disc[head[l]];
				int rv = disc[l];
				if(upper_bound(MX[v].begin(), MX[v].end(), rv) - lower_bound(MX[v].begin(), MX[v].end(), lv))
				ok |= 1;
				l = P[head[l]][0];	
			}
			int lv = disc[lc];
			int rv = disc[l];
			if(upper_bound(MX[v].begin(), MX[v].end(), rv) - lower_bound(MX[v].begin(), MX[v].end(), lv))
			ok |= 1;
			while(head[lc] != head[r])
			{
				int lv = disc[head[r]];
				int rv = disc[r];
				if(upper_bound(MX[v].begin(), MX[v].end(), rv) - lower_bound(MX[v].begin(), MX[v].end(), lv))
				ok |= 1;
				r = P[head[r]][0];
			}
			lv = disc[lc];
			rv = disc[r];
			if(upper_bound(MX[v].begin(), MX[v].end(), rv) - lower_bound(MX[v].begin(), MX[v].end(), lv))
			ok |= 1;
			if(ok)
			cout<<"Find\n";
			else cout<<"NotFind\n";	
		}
		for(int i=1;i<=n;i++)
		G[i].clear();
		MX.clear();	
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