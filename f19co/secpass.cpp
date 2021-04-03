#include <bits/stdc++.h>

typedef long long ll;

int lcp[100001];
ll prefc[100001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	while(T--)
	{
		memset(lcp, 0, sizeof(lcp));
		memset(prefc, 0, sizeof(prefc));
		int n;
		std::string s;
		std::cin>>n>>s;
		lcp[0] = 0;
		for(int i=1;i<n;i++)
		{
			int j = lcp[i-1];
			while(j && (s[i] != s[j]))
			j = lcp[j-1];
			if(s[i] == s[j])
			j++;
			lcp[i] = j;	
		}
		for(int i=0;i<n;i++)
		prefc[lcp[i]]++;
		for(int i=n-1;i>0;i--)
		prefc[lcp[i-1]] += prefc[i];
		for(int i=0;i<=n;i++)
		prefc[i]++;
		int ans = 0, px = -1;
		for(int i=1;i<=n;i++)
		{
			if(ans < prefc[i])
			{
				px = i;
				ans = prefc[i];
			}
			else if((ans == prefc[i]) && (i > px))
			px = i;	
		}	
		for(int i=0;i<px;i++)
		std::cout<<s[i];
		std::cout<<"\n";	
	}
	return 0;
}