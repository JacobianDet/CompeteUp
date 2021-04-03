#include <bits/stdc++.h>
#define CHOR 100001
#define pb push_back

std::vector<int> G[CHOR];
int ans = 0;

int dfs_visit(int s, int p)
{
	int x = 1;
	for(int i=0,j=(int)G[s].size();i<j;i++)
	{
		if(G[s][i] != p)
		x += dfs_visit(G[s][i], s);	
	}	
	if(!(x%2))
	{
		ans++;
		return 0;
	}	
	else return 1;
}

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		std::cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}
	if(n%2)
	std::cout<<"-1\n";
	else
	{	
		int x = dfs_visit(1, 0);
		std::cout<<ans-1<<"\n";
	}	
	return 0;
}