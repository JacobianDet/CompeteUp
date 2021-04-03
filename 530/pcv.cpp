#include <bits/stdc++.h>
#define mp std::make_pair

bool memo[201][201], vis[201][201];
std::pair<int, int> par[201][201];
int n;
std::string s;

bool zfx(int i, int k)
{
	//std::cout<<i<<" "<<k<<"\n";
	if(k < 0)
	{
		//std::cout<<"AMMA1\n";
		return 0;	
	}	
	else if(i == n)
	{	
		if(k == 0)
		{	
			//std::cout<<"AMMA2\n";
			return 1;
		}	
		else 
		{
			//std::cout<<"AMMA3\n";
			return 0;
		}	
	}	
	if(vis[i][k])
	{	
		//std::cout<<"AMMA4\n";
		return memo[i][k];
	}	
	bool ans = 0;
	if((i+1 < n) && (s[i+1] == '?'))	
	{
		if(zfx(i+2, k-1))
		{	
			ans |= zfx(i+2, k-1);
			par[i][k] = mp(i+2, k-1);
		}
		else if(zfx(i+2, k))
		{
			ans |= zfx(i+2, k);
			par[i][k] = mp(i+2, k);
		}	
	}	
	else if((i+1 < n) && (s[i+1] == '*'))
	{
		for(int j=0;j<=k;j++)
		{
			if(zfx(i+2, k-j))
			{
				ans |= zfx(i+2, k-j);
				par[i][k] = mp(i+2, k-j);
			}	
		}	
	}	
	else 
	{
		ans |= zfx(i+1, k-1);
		par[i][k] = mp(i+1, k-1);
	}	
	vis[i][k] = 1;
	memo[i][k] = ans;
	return ans;
}

int main(void)
{
	memset(vis, 0, sizeof(vis));
	memset(memo, 0, sizeof(memo));
	for(int i=0;i<201;i++)
	{
		for(int j=0;j<201;j++)
		par[i][j] = mp(i, j);	
	}	
	int k;
	std::cin>>s>>k;
	n = (int)s.size();
	bool ans = zfx(0, k);
	if(!ans)
	std::cout<<"Impossible\n";
	else
	{
		int s1 = 0, s2 = k;
		while(s1 < n)
		{
			int st1 = par[s1][s2].first;
			int st2 = par[s1][s2].second;
			for(int i=0;i<(s2-st2);i++)
			std::cout<<s[s1];
			s1 = st1;
			s2 = st2;	
		}	
		std::cout<<"\n";
	}	
	return 0;
}