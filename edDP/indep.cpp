#include <bits/stdc++.h>
#define pb push_back
#define MOD 1000000007

typedef long long ll;

std::vector<int> G[100001];
ll memo[100001][2];

ll dfs_visit(int s, int p, bool col)
{
	if(memo[s][col] != -1)
	return memo[s][col];
	ll ans = 1;
	for(auto u : G[s])
	{
		if(u != p)
		{
			if(!col)
			ans = ((ans%MOD) * (((dfs_visit(u, s, col)%MOD) + (dfs_visit(u, s, col ^ 1)%MOD))%MOD))%MOD;
			else ans = ((ans%MOD) * (dfs_visit(u, s, col ^ 1)%MOD))%MOD;	
		}
	}
	memo[s][col] = ans;
	return ans;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(memo, -1, sizeof(memo));
	int n;
	std::cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		std::cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}
	ll ans = ((dfs_visit(1, -1, 0)%MOD) + (dfs_visit(1, -1, 1)%MOD))%MOD;
	std::cout<<ans<<"\n";
	return 0;
}