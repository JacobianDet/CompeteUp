#include <bits/stdc++.h>

std::string a,b;
int memo[5001][5001];

int strmrg(int n, int m)
{
	if(!n & !m)
	return 0;	
	else if(!n)
	{
		int ctr = 0;
		for(int i=m-1;i>=0;i--)
		{	
			if(!i)
			ctr++;	
			else if(b[i] != b[i-1])
			ctr++;	
		}		
		return ctr;	
	}	
	else if(!m)
	{
		int ctr = 0;
		for(int i=n-1;i>=0;i--)
		{	
			if(!i)
			ctr++;	
			else if(a[i] != a[i-1])
			ctr++;	
		}		
		return ctr;	
	}	
	if(memo[n][m] != -1)
	return memo[n][m];	
	int i=0,j=0;
	int ans = 1e7;
	if(a[n-1] == b[m-1])
	{
		while((n-i >= 0) && (a[n-1-i] == a[n-1]))
		i++;	
		while((m-j >= 0) && (b[m-1-j] == b[m-1]))
		j++;
		ans = 1 + strmrg(n-i, m-j);

	}	
	else
	{
		while((n-i >= 0) && (a[n-1-i] == a[n-1]))
		i++;	
		while((m-j >= 0) && (b[m-1-j] == b[m-1]))
		j++;
		ans = 1 + std::min(strmrg(n-i, m), strmrg(n, m-j));
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
		int n,m;
		std::cin>>n>>m;
		std::cin>>a>>b;
		int ans = strmrg(n, m);
		std::cout<<ans<<"\n";
	}	
	return 0;
}