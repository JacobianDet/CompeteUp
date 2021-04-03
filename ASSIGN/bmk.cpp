#include <bits/stdc++.h>

typedef long long ll;

int n;
bool cost[21][21];
ll memo[1<<21];

ll ment(int mask)
{
	if(mask == ((1<<n)-1))
	return 1;
	if(memo[mask] != -1)
	return memo[mask];
	int x = __builtin_popcount(mask);
	ll ans = 0;
	for(int i=0;i<n;i++)
	{
		if(mask & (1<<i))
		continue;
		else
		{
			if(cost[x][i])
			ans += ment(mask | (1<<i));	
		}	
	}
	memo[mask] = ans;
	return ans;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(cost,0,sizeof(cost));
	int T;
	std::cin>>T;
	while(T--)
	{
		memset(memo,-1,sizeof(memo));
		std::cin>>n;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			std::cin>>cost[i][j];	
		}
		ll ans = ment(0);
		std::cout<<ans<<"\n";
	}	
	return 0;
}