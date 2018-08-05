#include <bits/stdc++.h>

int memo[1001][1001][2];
std::string s1,s2;

void swapp(char &x, char &y)
{
	char temp = x;
	x = y;
	y = temp;
}

int advedist(int n, int m, bool s)
{
	if(n == 0 && m == 0)
	return 0;
	else if(n == 0)
	return m;
	else if(m == 0)
	return n;
	if(memo[n][m][s] != -1)
	return memo[n][m][s];	
	int ans = 1e7;
	int ind = -1;
	if(s1[n-1] == s2[m-1])
	ans = advedist(n-1, m-1, 0);
	else
	{
		if(s)
		ans = std::min(ans, 1 + advedist(n-1, m, s));
		else
		{	
			ans = std::min(ans, 1 + advedist(n-1, m, s));
			ans = std::min(ans, 1 + advedist(n, m-1, s));
			ans = std::min(ans, 1 + advedist(n-1, m-1, s));
		}	
		if(s2[m-2] == s1[n-1])
		{	
			for(int i=n-1;i>=0;i--)
			{
				if(s1[i] == s2[m-1])
				{
					ind = i;
					break;
				}	
			}	
			if(ind != -1)
			{	
				swapp(s1[ind], s1[n-1]);
				ans = std::min(ans, 1 + advedist(n-1, m-1, 1));
				swapp(s1[ind], s1[n-1]);
			}	
		}		
	}		
	memo[n][m][s] = ans;
	return ans;
}

int main(void)
{
	std::cin>>s1>>s2;
	while(s1 != "*" && s2 != "*")
	{
		memset(memo,-1,sizeof(memo));
		int n = (int)s1.size();
		int m = (int)s2.size();
		int ans = advedist(n, m, 0);
		std::cout<<ans<<"\n";
		std::cin>>s1>>s2;
	}	
	return 0;
}