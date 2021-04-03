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

int ar[MV], cord[MV], av[MV];
ll arr[MV];
bool vis[MV], ant[MV];
VI G[MV], RG[MV], SCC[MV];
vector<PII> ed;
VI finx;
MPII use;

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
	SCC[x].pb(s);
	cord[s] = x;
	vis[s] = 1;
	for(auto u : RG[s])
	{
		if(!vis[u])
		dfs_vis2(u, x);	
	}
	return;
}

bool dfs_vis3(int s)
{
	vis[s] = 1;
	int vfx = -1;
	bool ok = 1, cx = 0;
	for(auto u : G[s])
	{
		cx = 1;
		if(!vis[u])
		{
			ok &= dfs_vis3(u);
			vfx = max(vfx, av[u]);
		}
		else 
		{
			ok &= ant[u];
			vfx = max(vfx, av[u]);
		}
	}
	if((av[s] != -1) && (vfx + 1 > av[s]) && cx)
	ok = 0;
	ant[s] = ok;
	av[s] = ((av[s] == -1) ? vfx + 1 : av[s]);
	return ok;
}

void solve(int T)
{
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>ar[i];
	std::string s;
	std::cin>>s;
	for(int i=0;i<n-1;i++)
	{
		if(s[i] == '>')
		{
			ed.pb(mp(i+1, i+2));
			RG[i+2].pb(i+1);	
			G[i+1].pb(i+2);
		}	
		else if(s[i] == '<')
		{	
			ed.pb(mp(i+2, i+1));
			RG[i+1].pb(i+2);
			G[i+2].pb(i+1);
		}	
		else
		{
			ed.pb(mp(i+1, i+2));
			ed.pb(mp(i+2, i+1));
			RG[i+1].pb(i+2);
			RG[i+2].pb(i+1);
			G[i+1].pb(i+2);
			G[i+2].pb(i+1);
		}	
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		dfs_vis1(i);	
	}	
	std::reverse(finx.begin(), finx.end());
	memset(vis, 0, sizeof(vis));
	int x = 0;
	for(auto u : finx)
	{
		if(!vis[u])
		{
			x++;
			dfs_vis2(u, x);
		}
	}
	bool ok = 1;
	for(int i=1;i<=x;i++)
	{
		int t = -1;
		for(auto u : SCC[i])
		{
			if((t == -1) && (ar[u] != -1))
			t = ar[u];	
			else if((ar[u] != -1) && (t != ar[u]))
			{
				ok = 0;
				break;
			}
		}
		if(!ok)
		break;
		else av[i] = t;	
	}
	if(!ok)
	std::cout<<"NO\n";	
	else
	{
		for(int i=1;i<=n;i++)
		G[i].clear();
		for(auto u : ed)
		{
			int s = cord[u.ff], d = cord[u.ss];
			if(use[mp(s, d)] || use[mp(d, s)] || (d == s))
			continue;
			G[s].pb(d);
			use[mp(s, d)] = 1;
			use[mp(d, s)] = 1;
		}	
		memset(vis, 0, sizeof(vis));
		for(int i=1;i<=x;i++)
		{
			if(!vis[i])
			ok &= dfs_vis3(i);	
		}
		if(ok)
		std::cout<<"YES\n";
		else std::cout<<"NO\n";	
	}	
	for(int i=1;i<=n;i++)
	{
		G[i].clear();
		RG[i].clear();
		vis[i] = 0;
		ant[i] = 0;
		av[i] = 0;
		SCC[i].clear();
	}	
	finx.clear();
	ed.clear();
	use.clear();
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