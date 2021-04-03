#include <bits/stdc++.h>
#define pb push_back

int G[1001];
int vis[1001];

int dfs_visit(int s)
{
	vis[s] = 1;
	int ax = 0;
	if(!vis[G[s]])
	ax = dfs_visit(G[s]);
	else if(vis[G[s]] == 1)
	ax = G[s];
	vis[s] = 2;
	return ax;
}

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	{
		int p;
		std::cin>>p;
		G[i] = p;
	}	
	for(int i=1;i<=n;i++)
	{
		memset(vis, 0, sizeof(vis));
		std::cout<<dfs_visit(i)<<" ";
	}	
	std::cout<<"\n";
	return 0;
}