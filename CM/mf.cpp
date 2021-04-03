#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair
#define CHOR 100001

typedef long long ll;

std::pair<int, int> E[10*CHOR];
std::vector<int> G[CHOR];
std::vector<int> RG[CHOR];
int comp[CHOR], indeg[CHOR];
ll ccx[CHOR];
bool vis[CHOR];
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
	ccx[x]++;
	comp[s] = x;
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
	int n,m;
	std::cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int s,d;
		std::cin>>s>>d;
		E[i] = mp(s, d);
		G[s].pb(d);
		RG[d].pb(s);
	}
	memset(vis, 0, sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		dfs_vis1(i);	
	}	
	std::reverse(finx.begin(), finx.end());
	int x = 0;
	memset(vis, 0, sizeof(vis));
	for(int i=0;i<n;i++)
	{
		if(!vis[finx[i]])
		{
			x++;
			dfs_vis2(finx[i], x);
		}		
	}
	for(int i=1;i<=n;i++)
	{
		RG[i].clear();
		G[i].clear();
	}	
	for(int i=0;i<m;i++)
	{
		int s = E[i].first, d = E[i].second;
		s = comp[s];
		d = comp[d];
		if(s == d)
		continue;
		else indeg[d]++;	
	}
	int sc = 0;
	for(int i=1;i<=x;i++)
	{
		if(!indeg[i])
		sc++;	
	}
	std::cout<<sc<<"\n";
	return 0;
}