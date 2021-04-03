#include <bits/stdc++.h>
#define INF 100000000

int n, h[100001], memo[100001];

int FROG1(int i)
{
	if(i == n)
	return 0;
	if(memo[i] != -1)
	return memo[i];	
	int ans = INF;
	if(i < n-1)
	ans = std::min(abs(h[i] - h[i+1]) + FROG1(i+1), abs(h[i] - h[i+2]) + FROG1(i+2));
	else ans = abs(h[i] - h[i+1]) + FROG1(i+1);
	memo[i] = ans;
	return ans;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(memo, -1, sizeof(memo));
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>h[i];
	int ans = FROG1(1);
	std::cout<<ans<<"\n";
	return 0;
}