#include <bits/stdc++.h>

int pref[201];
int memo[200][200];
int m;

int rock(int n, int c)
{
	if(n + 1 == m)
	{
		int x = pref[n+1] - pref[n-c];
		if(x > 0)
		return c+1;
		else return 0;	
	}	
	if(memo[n][c] != -1)
	return memo[n][c];	
	int ans = 0;
	int x = pref[n+1] - pref[n-c];
	if(x > 0)
	ans = std::max(c+1 + rock(n+1, 0), rock(n+1, c+1));
	else ans = std::max(rock(n+1, 0), rock(n+1, c+1));
	memo[n][c] = ans;
	return ans;	
}

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		memset(pref,0,sizeof(pref));
		memset(memo,-1,sizeof(memo));
		std::cin>>m;
		std::string s;
		std::cin>>s;
		for(int i=0;i<m;i++)
		pref[i+1] = pref[i] + ((s[i] == '1') ? 1 : -1);
		int tans = rock(0, 0);
		std::cout<<tans<<"\n";
		/*for(int i=0;i<=m;i++)
		std::cout<<pref[i]<<" ";
		std::cout<<"\n";*/	
	}	
	return 0;
}