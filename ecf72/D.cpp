#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MV 5001
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

int vis[MV], col[MV];
ll arr[MV];
VI G[MV];
PII E[MV];
MPII cord;

void dfs_visit(int s)
{
	vis[s] = 1;
	for(auto u : G[s])
	{
		if(!vis[u])
		{	
			col[cord[mp(s, u)]] = 1;
			dfs_visit(u);	
		}
		else if(vis[u] == 2)
		col[cord[mp(s, u)]] = 1;
		else col[cord[mp(s, u)]] = 2;
	}
	vis[s] = 2;
	return;
}

void solve(int T)
{
	int n,m;
	std::cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		std::cin>>E[i].ff>>E[i].ss;
		G[E[i].ff].pb(E[i].ss);
		cord[E[i]] = i;
	}
	for(int i=1;i<=n;i++)
	{	
		if(!vis[i])
		dfs_visit(i);
	}		
	int cx = 1;
	for(int i=0;i<m;i++)
	cx = max(cx, col[i]);
	std::cout<<cx<<"\n";
	for(int i=0;i<m;i++)
	std::cout<<col[i]<<" ";
	std::cout<<"\n";
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