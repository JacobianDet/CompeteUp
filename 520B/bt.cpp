#include <bits/stdc++.h>

int memo[200001], vis[200001];
int m;

int tbt(int n)
{
	if(n == m)
	return 0;
	else if(vis[n] == 1 || n <= 0)
	return 10000000;
	if(vis[n] == 2)
	return memo[n];
	vis[n] = 1;
	int ans = 0;
	if(n < m)
	ans = std::min(1 + tbt(n<<1), 1 + tbt(n-1));
	else ans = (n - m) + tbt(m);
	memo[n] = ans;
	vis[n] = 2;
	return ans;
}


int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(memo, -1, sizeof(memo));
	memset(vis, 0, sizeof(vis));
	int n;
	std::cin>>n>>m;
	int ans = tbt(n);
	std::cout<<ans<<"\n";
	return 0;
}