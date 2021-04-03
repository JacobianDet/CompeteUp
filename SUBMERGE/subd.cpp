#include <bits/stdc++.h>
#define pb push_back

std::vector<int> G[100001];
int lt[100001], dsc[100001];
bool vis[100001];
int tx;

int dfs_visit(int s, int p)
{
	vis[s] = 1;
	dsc[s] = lt[s] = ++tx;
	int chd = 0, artpt = 0;
	bool ok = 0;
	for(auto u : G[s])
	{
		if(!vis[u])
		{
			chd++;
			artpt += dfs_visit(u, s);
			lt[s] = std::min(lt[s], lt[u]);
			if(lt[u] >= dsc[s] && p != -1 && !ok)
			{
				ok = 1;
				artpt++;
			}	
		}
		else if(u != p)
		lt[s] = std::min(lt[s], dsc[u]);
	}
	if(p == -1 && chd > 1)
	artpt++;
	return artpt;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m;
	std::cin>>n>>m;
	while(n && m)
	{
		tx = 0;
		for(int i=1;i<=n;i++)
		G[i].clear();
		memset(vis, 0, sizeof(vis));
		memset(lt, 0, sizeof(lt));
		memset(dsc, 0, sizeof(dsc));
		for(int i=0;i<m;i++)
		{
			int s,d;
			std::cin>>s>>d;
			G[s].pb(d);
			G[d].pb(s);
		}
		int res = dfs_visit(1, -1);
		std::cout<<res<<"\n";
		std::cin>>n>>m;
	}
	return 0;
}