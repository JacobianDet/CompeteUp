#include <bits/stdc++.h>
#define pb push_back

std::vector<int> G[100001];
int memo[100001][2];

void dfs_visit(int s, int p)
{
	for(auto u : G[s])
	{
		if(u != p)
		{
			dfs_visit(u, s);
			memo[s][0] += memo[u][1];
			memo[s][1] += std::min(memo[u][0], memo[u][1]);
		}
	}
	memo[s][1]++;
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		std::cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}	
	dfs_visit(1, -1);
	std::cout<<std::min(memo[1][0], memo[1][1])<<"\n";
	return 0;
}