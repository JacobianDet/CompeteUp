#include <bits/stdc++.h>
#define INF 10000000000000

typedef long long ll;

int w[101];
ll v[101];
ll memo[101][100001];

ll knap(int n, int W)
{
	if(W < 0)
	return -INF;
	else if(!n)
	return 0;
	if(memo[n][W] != -1)
	return memo[n][W];
	ll ans = 0;
	ans = std::max(v[n] + knap(n-1, W-w[n]), knap(n-1, W));
	memo[n][W] = ans;
	return ans;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(memo, -1, sizeof(memo));
	int n,W;
	std::cin>>n>>W;
	for(int i=1;i<=n;i++)
	std::cin>>w[i]>>v[i];
	ll ans = knap(n, W);
	std::cout<<ans<<"\n";
	return 0;	
}