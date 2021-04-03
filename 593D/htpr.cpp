#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MV 200001
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

int par[MV], lvl[MV], ed[MV], Z[MV], P[MV][LMV];
ll arr[MV];
vector<PII> G[MV];

void dfs_visit(int s, int p)
{
	lvl[s] = 0; 
	par[s] = 0;
	if(p != -1)
	lvl[s] = lvl[p] + 1;
	par[s] = p;
	for(auto u : G[s])
	{
		if(u.ff != p)
		{	
			ed[u.ff] = u.ss;
			dfs_visit(u.ff, s);
		}			
	}	
	return;
}

void ST_build(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;(1<<j)<=n;j++)
		P[i][j] = -1;	
	}
	for(int i=1;i<=n;i++)
	{	
		Z[i] = i;
		P[i][0] = par[i];
	}	
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

int LCA_find(int p, int q)
{
	if(lvl[p] < lvl[q])
	{
		int tmp = p;
		p = q;
		q = tmp;
	}
	int l2 = 0;
	for(l2=0;(1<<l2)<=lvl[p];l2++);
	l2--;
	for(int i=l2;i>=0;i--)
	{
		if((lvl[p] - (1<<i)) >= lvl[q])
		p = P[p][i];	
	}
	if(p == q)
	return p;	
	for(int i=l2;i>=0;i--)
	{
		if((P[p][i] != -1) && (P[p][i] != P[q][i]))
		{
			p = P[p][i];
			q = P[q][i];
		}	
	}	
	return P[p][0];
}

int up(int x)
{
	if((Z[x] != 1) && (arr[ed[Z[x]]] < 2))
	Z[x] = up(P[Z[x]][0]);
	return Z[x];
}

ll query(int a, int b, ll w)
{
	int lc = LCA_find(a, b);
	while(w && (a != lc))
	{
		int u = up(a);
		if(lvl[u] <= lvl[lc])
		break;	
		w /= arr[ed[u]];
		a = P[u][0];
	}
	while(w && (b != lc))
	{
		int u = up(b);
		if(lvl[u] <= lvl[lc])
		break;	
		w /= arr[ed[u]];
		b = P[u][0];
	}
	return w;
}

void solve(int T)
{
	int n,m;
	std::cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		int s,d;
		ll w;
		std::cin>>s>>d>>w;
		G[s].pb(mp(d, i));
		G[d].pb(mp(s, i));
		arr[i] = w;
	}	
	dfs_visit(1, -1);
	ST_build(n);
	while(m--)
	{
		int ty;
		std::cin>>ty;
		if(--ty)
		{
			int ix;
			ll w;
			std::cin>>ix>>w;
			arr[ix] = w;
		}
		else
		{
			int s,d;
			ll w;
			std::cin>>s>>d>>w;
			std::cout<<query(s, d, w)<<"\n";
		}
	}
	return;
}

int main(void)
{
	FLASH();
	int T;
	T = 1;
	while(T--)
	solve(T);
	return 0;
}