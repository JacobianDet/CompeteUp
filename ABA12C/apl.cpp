#include <bits/stdc++.h>
#define CHOR 10000000

int a[110],K;
int memo[110][110][110];

int apple(int i, int k, int p)
{	
	if(!k && (p >= 0))
	return 0;
	else if((i == K+1) || (p < 0) || (k < 0))
	return CHOR;	
	if(memo[i][k][p] != -1)
	return memo[i][k][p];	
	int ans = CHOR;
	if(a[i] != -1)
	ans = std::min(a[i] + apple(i+1, k-i, p-1), std::min(a[i] + apple(i, k-i, p-1), apple(i+1, k, p)));
	else ans = apple(i+1, k, p);	
	memo[i][k][p] = ans;
	return ans;
}

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		memset(memo,-1,sizeof(memo));
		int n;
		std::cin>>n>>K;
		for(int i=1;i<=K;i++)
		std::cin>>a[i];		
		int ans = apple(1, K, n);
		if(ans == CHOR)
		ans = -1;
		std::cout<<ans<<"\n";
	}	
	return 0;
}