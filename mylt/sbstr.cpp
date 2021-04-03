#include <bits/stdc++.h>
#define pb push_back

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		std::string s;
		int k;
		std::cin>>s>>k;
		int ans = 0;
		for(int i=0,j=(int)s.size();i<j;i++)
		{
			int ctr[26];
			memset(ctr, 0, sizeof(ctr));
			std::vector<int> Z;
			for(int t=0;t<j-i;t++)
			{
				if(!ctr[s[i+t] - 97])
				{
					ctr[(s[i+t] - 97)]++;
					Z.pb((s[i+t]-97));
				}
				else ctr[(s[i+t] - 97)]++;
				if(Z.size() < k)
				continue;
				else
				{
					bool ok = 1;
					for(int w=1,x=(int)Z.size();w<x;w++)
					{
						if(ctr[Z[w]] != ctr[Z[0]])
						{
							ok = 0;
							break;
						}	
					}
					if(ok)
					ans++;	
				}	
			}	
		}	
		std::cout<<ans<<"\n";	
	}
	return 0;	
}