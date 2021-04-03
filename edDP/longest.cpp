#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

std::vector<int> G[100001];
bool vis[100001];
std::pair<int, int> memo[100001];

std::pair<int, int> dfs_visit(int s)
{
	if(vis[s])
	return memo[s];
	int g = 0, h1 = 0;
	for(auto u : G[s])
	{
		std::pair<int, int> px = dfs_visit(u);
		g = std::max(g, px.first);
		if(px.second > h1)
		h1 = px.second;
	}	
	vis[s] = 1;
	g = std::max(g, h1);
	memo[s] = mp(g, h1 + 1);
	return memo[s];
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
		G[s].pb(d);
	}
	for(int i=1;i<=n;i++)
	memo[i] = mp(0, 0);
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		ans = std::max(ans, dfs_visit(i).first);
	}
	std::cout<<ans<<"\n";
	return 0;	
}