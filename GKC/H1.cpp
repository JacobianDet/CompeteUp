#include <bits/stdc++.h>

typedef long long ll;

std::string s[1001];
bool mark[1001];

int main(void)
{
	freopen("H1.in", "r", stdin);
	freopen("H1.txt", "w", stdout);
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		memset(mark, 0, sizeof(mark));
		int n,p;
		std::cin>>n>>p;
		for(int i=0;i<p;i++)
		std::cin>>s[i];
		for(int i=0;i<p;i++)
		{
			if(!mark[i])
			{	
				for(int j=i+1;j<p;j++)
				{
					if(!mark[j])
					{	
						bool ok = 1;
						for(int k=0,m=std::min((int)s[i].size(), (int)s[j].size());k<m;k++)
						{
							if(s[i][k] != s[j][k])
							{
								ok = 0;
								break;
							}	
						}	
						if(ok)
						{
							if((int)s[i].size() > (int)s[j].size())
							mark[i] = 1;
							else mark[j] = 1;	
						}	
					}	
				}
			}		
		}
		ll tans = (1LL<<n);
		for(int i=0;i<p;i++)
		{
			if(!mark[i])
			{
				ll sz = (int)s[i].size();
				tans -= (1LL<<(n-sz));
			}	
		}
		std::cout<<"Case #"<<t<<": "<<tans<<"\n";
	}
	return 0;
}