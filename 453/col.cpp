#include <bits/stdc++.h>
#define pb push_back

std::vector<std::vector<int> > G(10001);
std::vector<int> par(10001);
std::vector<int> col(10001);

int dfs_visit(int s)
{
	int f=0;
	for(int i=0,j=G[s].size();i<j;i++)
	{	
		par[G[s][i]] = s;
		f += dfs_visit(G[s][i]);
	}	
	if(s == 1 || col[s] != col[par[s]])
	f += 1;
	return f;
}

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=2;i<=n;i++)
	{
		int v;
		std::cin>>v;
		G[v].pb(i);
	}	
	for(int i=1;i<=n;i++)
	std::cin>>col[i];
	par[1] = 0;
	int ans = dfs_visit(1);
	std::cout<<ans<<"\n";
	return 0;	
}