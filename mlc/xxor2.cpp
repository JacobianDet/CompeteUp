#include <bits/stdc++.h>

int pref[100100][31];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,q;
	std::cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		int t;
		std::cin>>t;
		for(int j=30;j>=0;j--)
		pref[i][j] = pref[i-1][j] + ((t & (1 << j)) ? 1 : 0);
	}	
	for(int i=0;i<q;i++)
	{
		int l,r;
		std::cin>>l>>r;
		int sz = r-l+1;
		int az = 0;
		for(int j=30;j>=0;j--)
		{
			int cnt = pref[r][j] - pref[l-1][j];
			if(sz - cnt > cnt)
			az |= (1 << j);	
		}	
		std::cout<<az<<"\n";
	}	
	return 0;
}