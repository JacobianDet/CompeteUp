#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
#define MV 2000001
#define LMV 21
#define ff first
#define ss second
#define pb push_back
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

int ar[2001], rk[2001];
ll arr[2001];
ll tab[2001][2001], dtab[2001][2001];
bool vis[2001];

struct t3
{
	ll s, d, w;
}E[MV];

vector<PLL> G[2001];

bool cmpx(t3 A, t3 B)
{
	return (A.w < B.w);
}

class dsu
{
	public: int root(int x);
			bool find_union(int x, int y);
};

int dsu::root(int x)
{
	return (x == ar[x]) ? x : (ar[x] = root(ar[x]));
}

bool dsu::find_union(int x, int y)
{
	int rx = root(x);
	int ry = root(y);
	if(rx == ry)
	return 0;
	if(rk[rx] < rk[ry])
	{
		int tp = rx;
		rx = ry;
		ry = tp;
	}	
	ar[ry] = rx;
	if(rk[rx] == rk[ry])
	rk[rx]++;
	return 1;	
}

void dijkstra_find(int s, int n)
{
	for(int i=1;i<=n;i++)
	{	
		dtab[s][i] = INF;
		vis[i] = 0;
	}	
	dtab[s][s] = 0;
	set<pair<ll, ll> > Z;
	Z.ins(mp(0, s));
	while(!Z.empty())
	{
		pair<ll,ll> px = *Z.begin();
		Z.erase(Z.find(px));
		if(vis[px.ss])
		continue;
		vis[px.ss] = 1;
		int u = px.ss;
		for(auto v : G[u])
		{
			if(dtab[s][v.ff] > dtab[s][u] + v.ss)
			{
				dtab[s][v.ff] = dtab[s][u] + v.ss;
				Z.ins(mp(dtab[s][v.ff], v.ff));
			}	
		}
	}
	return;
}

void solve(int T)
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		cin>>tab[i][j];	
	}
	bool ok = 1;
	for(int i=1;i<=n;i++)
	{
		if(tab[i][i])
		ok = 0;	
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<n-i+1;j++)
		{
			if((tab[i][i+j] != tab[i+j][i]) || (!tab[i+j][i]))
			ok = 0;	
		}	
	}	
	if(!ok)
	cout<<"NO\n";
	else
	{
		int cx = 0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			E[cx++] = {i, j, tab[i][j]};	
		}
		sort(E, E+cx, cmpx);
		for(int i=1;i<=n;i++)
		{
			ar[i] = i;
			rk[i] = 0;
		}	
		dsu Z;
		for(int i=0;i<cx;i++)
		{
			int s = E[i].s;
			int d = E[i].d;
			if(Z.find_union(s, d))
			{
				G[s].pb(mp(d, E[i].w));
				G[d].pb(mp(s, E[i].w));
			}	
		}	
		for(int i=1;i<=n;i++)
		dijkstra_find(i, n);	
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(tab[i][j] != dtab[i][j])
				ok = 0;	
			}	
		}	
		if(ok)
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