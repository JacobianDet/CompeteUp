#include <bits/stdc++.h>
#define mp std::make_pair

std::string s1,s2;
int memo[3001][3001];
std::pair<int, int> par[3001][3001];

int LCS(int n, int m)
{
	if(!n || !m)
	return 0;
	if(memo[n][m] != -1)
	return memo[n][m];
	int ans = 0;
	if(s1[n-1] == s2[m-1])
	{	
		par[n][m] = mp(n-1, m-1);
		ans = 1 + LCS(n-1, m-1);
	}	
	else if(LCS(n-1, m) > LCS(n, m-1))
	{
		par[n][m] = mp(n-1, m);
		ans = LCS(n-1, m);
	}	
	else
	{
		par[n][m] = mp(n, m-1);
		ans = LCS(n, m-1);
	}
	memo[n][m] = ans;
	return ans;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(memo, -1, sizeof(memo));
	std::cin>>s1>>s2;
	int n = (int)s1.size();
	int m = (int)s2.size();
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		par[i][j] = mp(i, j);	
	}	
	int ans = LCS(n, m);
	int sz1 = n, sz2 = m;
	std::stack<char> Z;
	while(sz1 && sz2)
	{
		int st1 = par[sz1][sz2].first;
		int st2 = par[sz1][sz2].second;
		if(st1 == sz1-1 && st2 == sz2-1)
		Z.push(s1[sz1-1]);
		sz1 = st1;
		sz2	= st2;
	}	
	while(!Z.empty())
	{
		std::cout<<Z.top();
		Z.pop();
	}	
	std::cout<<"\n";
	return 0;
}