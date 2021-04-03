#include <bits/stdc++.h>
#define CHOR 200001
#define pb push_back

std::vector<int> G[CHOR];
bool vis[CHOR];

bool dfs_visit(int s)
{
	vis[s] = 1;
	bool ans = 1;
	if(G[s].size() != 2)
	ans = 0;	
	for(int i=0,j=(int)G[s].size();i<j;i++)
	{
		if(!vis[G[s][i]])
		ans &= dfs_visit(G[s][i]);	
	}	
	return ans;	
}

int main(void)
{
	int n,m;
	std::cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v;
		std::cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}	
	int ctr = 0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			if(dfs_visit(i))
			ctr++;	
		}
	}
	std::cout<<ctr<<"\n";	
	return 0;
}