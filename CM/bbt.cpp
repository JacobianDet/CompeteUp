#include <bits/stdc++.h>

int memo[10000001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=0;i<10000001;i++)
	memo[i] = 1000000000;
	memo[0] = 0;
	memo[1] = 1;
	for(int i=2;i<=n;i++)
	{
		memo[i] = std::min(memo[i], 1 + memo[i-1]);
		for(int j=2*i;j<=std::min(n, i*i);j+=i)
		memo[j] = std::min(memo[j], 1 + memo[i]);	
	}	
	std::cout<<memo[n]<<"\n";
	return 0;
}