#include <bits/stdc++.h>

std::string s1,s2;
int memo[2001][2001];

int edist(int n, int m)
{
	if(n == 0 && m == 0)
	return 0;
	else if(m == 0)
	return n;
	else if(n == 0)
	return m;
	if(memo[n][m] != -1)
	return memo[n][m];
	int ans = 1e7;
	if(s1[n-1] == s2[m-1])
	ans = edist(n-1, m-1);
	else
	{
		ans = std::min(ans, 1 + edist(n, m-1));
		ans = std::min(ans, 1 + edist(n-1, m));
		ans = std::min(ans, 1 + edist(n-1, m-1));
	}	
	memo[n][m] = ans;
	return ans;
}

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		memset(memo,-1,sizeof(memo));
		std::cin>>s1>>s2;
		int n = (int)s1.size();
		int m = (int)s2.size();
		int ans = edist(n,m);
		std::cout<<ans<<"\n";
	}	
	return 0;
}