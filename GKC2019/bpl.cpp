#include <bits/stdc++.h>

int pref[100001][26];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		memset(pref, 0, sizeof(pref));
		int n,q;
		std::cin>>n>>q;
		std::string s;
		std::cin>>s;
		for(int i=1;i<=n;i++)
		pref[i][s[i-1] - 'A']++;
		for(int i=1;i<=n;i++)
		{
			for(int c=0;c<26;c++)
			pref[i][c] += pref[i-1][c];	
		}	
		int ctx = 0;
		while(q--)
		{
			int l,r;
			std::cin>>l>>r;
			bool oc = 0, ok = 1;
			for(int i=0;i<26;i++)
			{
				if(!((pref[r][i] - pref[l-1][i]) & 1))
				continue;
				else if(!oc)
				oc = 1;
				else 
				{
					ok = 0;
					break;
				}	
			}
			if(ok)
			ctx++;	
		}
		std::cout<<"Case #"<<t<<": "<<ctx<<"\n";
	}
	return 0;
}