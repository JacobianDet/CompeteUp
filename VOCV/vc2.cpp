#include <bits/stdc++.h>
#define pb push_back
#define MOD 10007

typedef long long ll;

std::vector<int> G[100020];
ll memo[100020][2][2];

void dfs_visit(int s, int p)
{
	ll c0 = 1, c1 = 1;
	for(auto u : G[s])
	{
		if(u != p)
		{
			dfs_visit(u, s);
			memo[s][0][0] += memo[u][0][1];
			c0 = ((c0%MOD) * (memo[u][1][1]%MOD))%MOD;
			if(memo[u][0][0] < memo[u][0][1])
			{
				memo[s][0][1] += memo[u][0][0];
				c1 = ((c1%MOD) * (memo[u][1][0]%MOD))%MOD;
			}	
			else if(memo[u][0][0] > memo[u][0][1])
			{
				memo[s][0][1] += memo[u][0][1];
				c1 = ((c1%MOD) * (memo[u][1][1]%MOD))%MOD;
			}
			else
			{
				memo[s][0][1] += memo[u][0][1];
				c1 = ((c1%MOD) * (((memo[u][1][0]%MOD) + (memo[u][1][1]%MOD))%MOD))%MOD;
			}
		}
	}
	memo[s][0][1]++;
	memo[s][1][0] = c0;
	memo[s][1][1] = c1;
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	while(T--)
	{
		memset(memo, 0, sizeof(memo));
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
		if(memo[1][0][0] < memo[1][0][1])
		std::cout<<memo[1][0][0]<<" "<<memo[1][1][0]<<"\n";
		else if(memo[1][0][0] > memo[1][0][1])
		std::cout<<memo[1][0][1]<<" "<<memo[1][1][1]<<"\n";
		else std::cout<<memo[1][0][1]<<" "<<(((memo[1][1][1]%MOD) + (memo[1][1][0]%MOD))%MOD)<<"\n";
		for(int i=1;i<=n;i++)
		G[i].clear();	
	}
	return 0;
}