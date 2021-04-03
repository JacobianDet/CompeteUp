#include <bits/stdc++.h>

typedef long long ll;

ll grp[100001][26], mnkp[100001][26];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::string s;
	int k;
	std::cin>>s>>k;
	for(int i=0,j=(int)s.size();i<j;i++)
	grp[i%k][s[i] - 'a']++;
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<26;j++)
		mnkp[i][j] = 1000000000000;
	}
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<k;j++)
		{
			ll sx = 0;
			for(int x=0;x<26;x++)
			{
				ll sh = 0;
				if(i > x)
				sh = std::min(i-x, 26-i+x);
				else sh = std::min(x-i, i+26-x);
				sx += grp[j][x] * sh;
			}	
			mnkp[j][i] = std::min(mnkp[j][i], sx);
		}	
	}
	ll ans = 0;
	for(int i=0;i<k;i++)
	{
		ll mx = 1000000000000;
		for(int j=0;j<26;j++)
		mx = std::min(mx, mnkp[i][j]);
		ans += mx;	
	}	
	std::cout<<ans<<"\n";
}