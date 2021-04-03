#include <bits/stdc++.h>
#define INF 10000000000001
#define pb push_back

typedef long long ll;

ll G[501][501], memo[501][501];
int x[501];
std::vector<ll> Z;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		std::cin>>G[i][j];	
	}
	for(int i=1;i<=n;i++)
	std::cin>>x[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i != j)
			memo[i][j] = INF;	
		}
	}
	for(int i=n;i>0;i--)
	{
		for(int j=n;j>i;j--)
		{
			memo[x[i]][x[j]] = G[x[i]][x[j]];
			memo[x[j]][x[i]] = G[x[j]][x[i]];
		}	
		for(int j=n;j>i;j--)
		{
			for(int k=n;k>i;k--)
			{
				if(memo[x[i]][x[j]] > memo[x[i]][x[k]] + memo[x[k]][x[j]])
				memo[x[i]][x[j]] = memo[x[i]][x[k]] + memo[x[k]][x[j]];	
				if(memo[x[j]][x[i]] > memo[x[j]][x[k]] + memo[x[k]][x[i]])
				memo[x[j]][x[i]] = memo[x[j]][x[k]] + memo[x[k]][x[i]];	
			}	
		}	
		for(int j=n;j>i;j--)
		{
			for(int k=n;k>i;k--)
			{
				if(memo[x[j]][x[k]] > memo[x[j]][x[i]] + memo[x[i]][x[k]])
				memo[x[j]][x[k]] = memo[x[j]][x[i]] + memo[x[i]][x[k]];	
			}	
		}	
		ll ans = 0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(memo[i][j] != INF)
				ans += memo[i][j];
			}	
		}
		Z.pb(ans);
	}
	std::reverse(Z.begin(), Z.end());
	for(int i=0;i<n;i++)
	std::cout<<Z[i]<<" ";
	std::cout<<"\n";
	return 0;	
}