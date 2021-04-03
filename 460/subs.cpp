#include <bits/stdc++.h>
#define CHOR 300001
#define pb push_back

std::vector<std::vector<int> > G(CHOR);
int vis[CHOR];
int memo[CHOR][26];
std::string t;

bool dfs_cycle(int s)
{
	vis[s] = 1;
	bool x = 0;
	for(int i=0,j=(int)G[s].size();i<j;i++)
	{
		if(!vis[G[s][i]])
		x = dfs_cycle(G[s][i]);
		else if(vis[G[s][i]] == 1)
		x = 1;	
		if(x)
		break; 
	}	
	vis[s] = 2;
	return x;
}

void dfs_visit(int s)
{
	vis[s] = 1;
	for(int i=0,j=(int)G[s].size();i<j;i++)
	{
		if(!vis[G[s][i]])
		dfs_visit(G[s][i]);
		for(int k=0;k<26;k++)
		memo[s][k] = std::max(memo[s][k], memo[G[s][i]][k]);	
	}	
	memo[s][t[s-1]-'a']++;
	return;
}


int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m;
	std::cin>>n>>m;
	std::cin>>t;
	memset(memo, 0, sizeof(memo));
	for(int i=0;i<m;i++)
	{
		int s,d;
		std::cin>>s>>d;
		G[s].pb(d);
	}
	bool flag = 0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		flag = dfs_cycle(i);
		if(flag)
		break;	
	}
	if(flag)
	{
		std::cout<<"-1\n";
		return 0;
	}
	memset(vis, 0, sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		dfs_visit(i);	
	}
	int ans = -1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<26;j++)
		ans = std::max(ans, memo[i][j]);	
	}	
	std::cout<<ans<<"\n";
	return 0;
}