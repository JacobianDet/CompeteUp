#include <bits/stdc++.h>
#define INF 10000000000000

typedef long long ll;

int v[101];
ll w[101];
ll memo[2][100001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,W;
	std::cin>>n>>W;
	for(int i=1;i<=n;i++)
	std::cin>>w[i]>>v[i];
	for(int i=0;i<2;i++)
	{
		for(int V=0;V<100001;V++)
		memo[i][V] = INF;	
	}	
	memo[0][0] = 0;
	for(int i=1;i<=n;i++)
	{
		for(int V=0;V<100001;V++)
		{
			if((V - v[i]) >= 0)
			memo[1][V] = std::min(w[i] + memo[0][V-v[i]], memo[0][V]);	
			else memo[1][V] = memo[0][V];
		}
		for(int V=0;V<100001;V++)
		memo[0][V] = memo[1][V];	
	}
	int ans = 0;	
	for(int V=0;V<100001;V++)
	{
		if(memo[0][V] <= W)
		ans = std::max(ans, V);	
	}
	std::cout<<ans<<"\n";
	return 0;
}