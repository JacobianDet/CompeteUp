#include <bits/stdc++.h>
#define INF 100000000

int memo[31][31][51];

int chox(int n, int m, int k)
{
	if(!k || n*m == k)
	return 0;	
	if(memo[n][m][k] != -1)
	return memo[n][m][k];
	int ans = INF;
	for(int i=1;i<=m/2;i++)
	{
		if(n*i <= k && n*(m-i) <= k)
		ans = std::min(ans, n*n + std::min(chox(n, i, k-n*(m-i)), chox(n, m-i, k-n*i)));	
		else if(n*i <= k)
		ans = std::min(ans, n*n + std::min(chox(n, m-i, k-n*i), chox(n, m-i, k)));
		else ans = std::min(ans, n*n + std::min(chox(n, i, k), chox(n, m-i, k)));	
	}	
	for(int i=1;i<=n/2;i++)
	{
		if(i*m <= k && (n-i)*m <= k)
		ans = std::min(ans, m*m + std::min(chox(i, m, k-m*(n-i)), chox(n-i, m, k-i*m)));	
		else if(i*m <= k)
		ans = std::min(ans, m*m + std::min(chox(n-i, m, k-i*m), chox(n-i, m, k)));
		else ans = std::min(ans, m*m + std::min(chox(i, m, k), chox(n-i, m, k)));	
	}	
	memo[n][m][k] = ans;
	return ans;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
	memset(memo, -1, sizeof(memo));
	for(int i=30;i>0;i--)
	{
		for(int j=30;j>0;j--)
		{
			for(int k=50;k>0;k--)
			{
				if(i*j < k)
				continue;
				else memo[i][j][k] = chox(i, j, k);	
			}	
		}	
	}	
	int T;
	std::cin>>T;
	while(T--)
	{
		int n,m,k;
		std::cin>>n>>m>>k;
		std::cout<<memo[n][m][k]<<"\n";
	}	
	return 0;
}