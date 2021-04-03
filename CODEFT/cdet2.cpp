#include <bits/stdc++.h>

std::string t[16];
int chx[16][26], pat[26];

int main(void)
{
	std::string s;
	std::cin>>s;
	for(int i=0;i<s.size();i++)
	pat[s[i]-'a']++;
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>t[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<t[i].size();j++)
		chx[i][t[i][j]-'a']++;
	}
	int ans = 0;
	for(int i=0;i<(1<<n);i++)
	{
		int ctx[26];
		memset(ctx, 0, sizeof(ctx));
		for(int j=0;j<n;j++)
		{
			if(i & (1<<j))
			{
				for(int k=0;k<26;k++)
				ctx[k] += chx[j][k];		
			}
		}
		bool ok = 1;
		for(int j=0;j<26;j++)
		{
			if(ctx[j] > pat[j])
			{
				ok = 0;
				break;
			}		
		}	
		if(ok)
		ans = std::max(ans, __builtin_popcount(i));		
	}	
	std::cout<<ans<<"\n";
	return 0;
}