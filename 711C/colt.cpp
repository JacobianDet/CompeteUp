#include <bits/stdc++.h>

typedef long long ll;

int col[101];
ll cst[101][101], memo[101][101][101];
int m;

ll ammaji(int n, int k, int lc)
{
	if(k < 0)
	return 10000000000000000;
	else if(!n)
	{	
		if(!k)
		return 0;
		else return 10000000000000000;
	}	
	if(memo[n][k][lc] != -1)
	return memo[n][k][lc];
	ll ans = 10000000000000000;
	if(col[n])
	{
		if(col[n] != lc)
		ans = ammaji(n-1, k-1, col[n]);
		else ans = ammaji(n-1, k, col[n]);	
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			if(i != lc)
			ans = std::min(ans, cst[n][i] + ammaji(n-1, k-1, i));
			else ans = std::min(ans, cst[n][i] + ammaji(n-1, k, i));	
		}	
	}
	memo[n][k][lc] = ans;
	return ans;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(memo, -1, sizeof(memo));
	int n,k;
	std::cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	std::cin>>col[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		std::cin>>cst[i][j];	
	}	
	ll ans = ammaji(n, k, 0);
	if(ans >= 10000000000000000)
	std::cout<<"-1\n";
	else std::cout<<ans<<"\n";
	return 0;	
}