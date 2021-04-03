#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

std::vector<int> G[6001];
ll cvn[6001], memo1[6001], memo2[6001];

void dfs_visit(int s, int p)
{
	for(auto u : G[s])
	{
		if(u != p)
		{
			dfs_visit(u, s);
			memo1[s] += memo2[u];
			memo2[s] += std::max(memo1[u], memo2[u]);
		}
	}
	memo1[s] += cvn[s];
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int a1 = 1, a2 = 1;
	while(a1 || a2)
	{
		int n;
		std::cin>>n;
		for(int i=1;i<=n;i++)
		std::cin>>cvn[i];
		for(int i=1;i<=n;i++)
		{
			memo1[i] = 0;
			memo2[i] = 0;
			G[i].clear();
		}
		for(int i=0;i<n-1;i++)
		{
			int s,d;
			std::cin>>s>>d;
			G[s].pb(d);
			G[d].pb(s);
		}	
		std::cin>>a1>>a2;
		dfs_visit(1, -1);	
		std::cout<<std::max(memo1[1], memo2[1])<<"\n";
	}
	return 0;
}