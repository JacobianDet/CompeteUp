#include <bits/stdc++.h>
#define INF 1000000000

int n, k, h[100001], memo[100001];

int FROG2(int i)
{
	if(i == n)
	return 0;
	if(memo[i] != -1)
	return memo[i];	
	int ans = INF;
	for(int j=1;j<=k;j++)
	{
		if(i+j <= n)
		ans = std::min(ans, abs(h[i] - h[i+j]) + FROG2(i+j));	
	}	
	memo[i] = ans;
	return ans;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(memo, -1, sizeof(memo));
	std::cin>>n>>k;
	for(int i=1;i<=n;i++)
	std::cin>>h[i];
	int ans = FROG2(1);
	std::cout<<ans<<"\n";
	return 0;
}