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

int ar[2][MV], cord[MV], indeg[MV], fl[MV];
ll arr[MV];
bool vis[MV];
VI G[MV], RG[MV], SCC[MV];
VI finx;
MPII tw;

void dfs_vis1(int s)
{
	vis[s] = 1;
	for(auto u : G[s])
	{
		if(!vis[u])
		dfs_vis1(u);	
	}
	finx.pb(s);
	return;
}

void dfs_vis2(int s, int x)
{
	vis[s] = 1;
	cord[s] = x;
	SCC[x].pb(s);
	for(auto u : RG[s])
	{
		if(!vis[u])
		dfs_vis2(u, x);	
	}
	return;
}

void solve(int T)
{
	int n,k;
	std::cin>>n>>k;
	for(int i=0;i<n;i++)
	std::cin>>ar[0][i];
	for(int i=0;i<n;i++)
	std::cin>>ar[1][i];
	for(int i=0;i<n-1;i++)
	{
		G[ar[0][i]].pb(ar[0][i+1]);
		RG[ar[0][i+1]].pb(ar[0][i]);
		G[ar[1][i]].pb(ar[1][i+1]);
		RG[ar[1][i+1]].pb(ar[1][i]);
	}
	for(int i=1;i<=n;i++)
	{	
		if(!vis[i])
		dfs_vis1(i);
	}
	int x = 0;
	memset(vis, 0, sizeof(vis));
	std::reverse(finx.begin(), finx.end());
	for(auto u : finx)
	{
		if(!vis[u])
		{
			x++;
			dfs_vis2(u, x);
		}
	}
	if(x < k)
	std::cout<<"NO\n";
	else
	{	
		for(int i=1;i<=n;i++)
		{
			G[i].clear();
			RG[i].clear();
		}
		for(int i=0;i<n-1;i++)
		{
			int a = cord[ar[0][i]], b = cord[ar[0][i+1]], c = cord[ar[1][i]], d = cord[ar[1][i+1]];
			if((a != b) && !tw[mp(a, b)])
			{	
				tw[mp(a, b)] = 1;
				indeg[b]++;
				G[a].pb(b);
			}
			if((c != d) && !tw[mp(c, d)])
			{	
				tw[mp(c, d)] = 1;
				indeg[d]++;
				G[c].pb(d);
			}
		}
		finx.clear();
		memset(vis, 0, sizeof(vis));
		for(int i=1;i<=x;i++)
		{
			if(!vis[i])
			dfs_vis1(i);	
		}
		std::reverse(finx.begin(), finx.end());
		int y = 0;
		for(auto u : finx)
		{
			fl[u] = y;
			if(y < 25)
			y++;
		}
		std::cout<<"YES\n";
		for(int i=1;i<=n;i++)
		std::cout<<((char)(fl[cord[i]] + 'a'));
		std::cout<<"\n";		
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