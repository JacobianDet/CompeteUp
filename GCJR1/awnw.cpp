#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll T;
	std::cin>>T;
	for(ll t=1;t<=T;t++)
	{
		ll n,l;
		std::cin>>n>>l;
		std::string s[n];
		for(ll i=0;i<n;i++)
		std::cin>>s[i];
		bool ctr[l][26];
		ll cc[l];
		memset(cc,0,sizeof(cc));
		memset(ctr,0,sizeof(ctr));
		ll res = 1;
		for(ll i=0;i<l;i++)
		{
			for(ll j=0;j<n;j++)
			ctr[i][(s[j][i]-65)] = 1;
			for(ll j=0;j<26;j++)
			{
				if(ctr[i][j])
				cc[i]++;	
			}	
			res = res * cc[i];
		}	
		if(res == n)
		std::cout<<"Case #"<<t<<": "<<"-\n";
		else 
		{
			std::string ans;
			std::set<char> Z;
			for(ll i=0;i<n;i++)
			Z.insert(s[i][0]);
			for(std::set<char>::iterator it=Z.begin();it != Z.end();it++)
			{
				char c = *it;
				ll lt = 0;
				bool mark[26];
				memset(mark,0,sizeof(mark));
				for(ll i=0;i<n;i++)
				{
					if(s[i][0] == c)
					mark[s[i][1]-65] = 1;
				}	
				for(ll i=0;i<26;i++)
				{
					if(mark[i])
					lt++;	
				}	
				if(lt != cc[1])
				{
					for(ll i=0;i<26;i++)
					{
						if(!mark[i] && ctr[1][i])
						{	
							ans += c;
							ans += (char)(i+65);
							break;
						}		
					}	
				}
				if(ans.size() == 2)
				break;	
			}	
			std::cout<<"Case #"<<t<<": "<<ans<<"\n";	
		}	
	}
	return 0;	
}