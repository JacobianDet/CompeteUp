#include <bits/stdc++.h>

typedef long long ll;

ll G[21][21];
ll memo[(1<<20)];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		std::cin>>G[i][j];	
	}
	memo[(1<<n)-1] = 0;
	for(int i=n-1;i>=0;i--)
	{
		for(int mask = (1<<n)-1;mask>=0;mask--)
		{
			if(__builtin_popcount(mask) == i)
			{
				for(int j=n-1;j>=0;j--)
				{
					if(!(mask & (1<<j)))
					memo[mask] = std::max(memo[mask], G[i][j] + memo[mask | (1<<j)]);	
				}	
			}	
		}	
	}
	std::cout<<memo[0]<<"\n";
	return 0;
}