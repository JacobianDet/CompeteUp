#include <bits/stdc++.h>
#define pb push_back

int par[100001];
std::vector<int> G[100001];
int sx[100001];
int lvl[100001];

void dfs_vis1(int s)
{
	if(s)
	lvl[s] = 1 + lvl[par[s]];
	for(int i=0,j=(int)G[s].size();i<j;i++)
	dfs_vis1(G[s][i]);
	return;	
}

int dfs_vis2(int s, int x)
{
	int tot = 0;
	if(sx[s])
	{	
		tot += abs(lvl[s] - lvl[x]);
		x = s;	
	}	
	for(int i=0,j=(int)G[s].size();i<j;i++)
	tot += dfs_vis2(G[s][i], x);
	return tot;
}

int main(void)
{
	int T;
	std::cin>>T; 
	while(T--)
	{
		memset(lvl,0,sizeof(lvl));
		int n;
		std::cin>>n;
		for(int i=1;i<=n-1;i++)
		{	
			std::cin>>par[i];
			G[par[i]].pb(i);
		}	
		for(int i=0;i<n;i++)
		std::cin>>sx[i];
		dfs_vis1(0);
		int tot = dfs_vis2(0, 0);
		std::cout<<tot<<"\n";
		for(int i=0;i<n;i++)
		G[i].clear();	
	}	
	return 0;
}