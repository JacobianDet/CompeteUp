#include <bits/stdc++.h>

int n;
int pref[201];
int memo[201][201];

int rup(int i, int j)
{
	if(memo[i][j] != -1)
	return memo[i][j];	
	int x = pref[j] - pref[i-1];
	int ans = 0;
	if(x > 0)
	ans = j-i+1;
	else
	{
		for(int k=i;k<j;k++)
		ans = std::max(ans, rup(i, k) + rup(k+1, j));	
	}	
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
		memset(pref,0,sizeof(pref));
		std::cin>>n;
		std::string s;
		std::cin>>s;
		for(int i=0;i<n;i++)
		pref[i+1] = pref[i] + ((s[i] == '1') ? 1 : -1);	
		int ans = rup(1, n);
		std::cout<<ans<<"\n";
	}	
	return 0;
}