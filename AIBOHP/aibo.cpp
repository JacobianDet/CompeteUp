#include <bits/stdc++.h>

std::string s;
int memo[6100][6100];

int LCS(int i, int j)
{
	if(i == (int)s.size() || j == -1)
	return 0;
	if(memo[i][j] != -1)
	return memo[i][j];	
	int ans = 0;
	if(s[i] == s[j])
	ans = 1 + LCS(i+1, j-1);
	else ans = std::max(LCS(i+1, j), LCS(i, j-1));
	memo[i][j] = ans;
	return ans;
}


int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		memset(memo,-1,sizeof(memo));
		std::cin>>s;
		int n = (int)s.size();
		int lcs = LCS(0, n-1);
		std::cout<<n-lcs<<"\n";
	}	
	return 0;
}