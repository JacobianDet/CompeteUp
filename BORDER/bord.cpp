#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
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

int ar[MV], lcp[MV], P[MV][LMV], par[MV], lvl[MV];
ll arr[MV];
VI G[MV];

void dfs_visit(int s, int p)
{
	par[s] = p;
	lvl[s] = 0;
	if(p != -1)
	lvl[s] = 1 + lvl[p];	
	for(auto u : G[s])
	{
		if(u != p)
		dfs_visit(u, s);	
	}
	return;
}

void ST_build(int n)
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;(1<<j)<=n+1;j++)
		P[i][j] = -1;
	}
	for(int i=0;i<=n;i++)
	P[i][0] = par[i];
	for(int j=1;(1<<j)<=n+1;j++)
	{
		for(int i=0;i<=n;i++)
		{
			if(P[i][j-1] != -1)
			P[i][j] = P[P[i][j-1]][j-1];
		}	
	}
	return;	
}

int blift(int x, int k)
{
	int lx = 0;
	for(lx=1;(1<<lx)<=lvl[x];lx++);
	lx--;
	for(int i=lx;i>=0;i--)
	{
		if((lvl[x] - (1<<i)) >= k)
		x = P[x][i];
	}	
	return x;
}

void solve(int T)
{
	int n,q;
	std::cin>>n>>q;
	std::string s;
	std::cin>>s;
	for(int i=1;i<n;i++)
	{
		int j = lcp[i-1];
		while(j && (s[i] != s[j]))
		j = lcp[j-1];
		if(s[i] == s[j])
		j++;
		lcp[i] = j;	
	}
	for(int i=1;i<=n;i++)
	{
		G[lcp[i-1]].pb(i);
		G[i].pb(lcp[i-1]);
	}	
	dfs_visit(0, -1);
	ST_build(n);	
	while(q--)
	{
		int p,k;
		std::cin>>p>>k;
		if(k > lvl[p])
		std::cout<<"-1\n";
		else std::cout<<blift(p, k)<<"\n";	
	}
	for(int i=0;i<=n;i++)
	G[i].clear();	
	return;
}

int main(void)
{
	FLASH();
	int T;
	cin>>T;
	while(T--)
	solve(T);
	return 0;
}