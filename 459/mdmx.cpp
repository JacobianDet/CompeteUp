#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

std::vector<std::pair<int, int> > G[10001];
int memo[101][101][26][2];

int winm(int s1, int s2, int val, bool p)
{
	if(memo[s1][s2][val][p] != -1)
	return memo[s1][s2][val][p];
	int ans = 0, u = 0;
	if(!p)
	{
		ans = 0;
		u = s1;
	}
	else
	{
		ans = 1;
		u = s2;
	}
	for(int i=0,j=(int)G[u].size();i<j;i++)
	{
		int v = G[u][i].first;
		char w = G[u][i].second;
		if(w >= val)
		{
			if(!p)
			ans |= winm(v, s2, w, 1);
			else ans &= winm(s1, v, w, 0);
		}
	}
	memo[s1][s2][val][p] = ans;
	return ans;
}

int main(void)
{
	memset(memo, -1, sizeof(memo));
	int n,m;
	std::cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int s,d;
		char w;
		std::cin>>s>>d>>w;
		G[s].pb(mp(d, (w-'a')));
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(winm(i, j, 0, 0))
			std::cout<<"A";
			else std::cout<<"B";
		}
		std::cout<<"\n";
	}
	return 0;
}
