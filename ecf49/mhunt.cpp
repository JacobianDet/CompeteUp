#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair
#define CHOR 200001

std::vector<int> G[CHOR];
std::vector<int> RG[CHOR];
std::pair<int, int> E[CHOR];
bool vis[CHOR];
int SCC[CHOR], cst[CHOR], cord[CHOR];
std::vector<int> finx;

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
	for(auto u : RG[s])
	{
		if(!vis[u])
		dfs_vis2(u, x);	
	}	
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>cst[i];
	for(int i=1;i<=n;i++)
	{
		int cz;
		std::cin>>cz;
		E[i-1] = mp(i, cz);
		G[i].pb(cz);
		RG[cz].pb(i);
	}	
	for(int i=1;i<=n;i++)
	SCC[i] = CHOR;
	for(int i=1;i<=n;i++)
	{	
		if(!vis[i])
		dfs_vis1(i);
	}
	int x = 0;
	memset(vis, 0, sizeof(vis));
	std::reverse(finx.begin(), finx.end());
	for(int i=0;i<n;i++)
	{
		if(!vis[finx[i]])
		{
			x++;
			dfs_vis2(finx[i], x);
		}	
		G[i+1].clear();
	}	
	for(int i=1;i<=n;i++)
	SCC[cord[i]] = std::min(SCC[cord[i]], cst[i]);
	for(int i=0;i<n;i++)
	{
		int u = E[i].first;
		int v = E[i].second;
		u = cord[u];
		v = cord[v];
		if(u != v)
		G[u].pb(v);	
	}	
	int tot = 0;
	for(int i=1;i<=x;i++)
	{
		if((int)G[i].size() == 0)
		tot += SCC[i];	
	}
	std::cout<<tot<<"\n";
	return 0;
}