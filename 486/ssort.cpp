#include <bits/stdc++.h>

bool cmp(std::string a, std::string b)
{
	return ((int)a.size() < (int)b.size());
}

int main(void)
{
	int n;
	std::cin>>n;
	std::string s[n];
	for(int i=0;i<n;i++)
	std::cin>>s[i];
	std::sort(s, s+n, cmp);	
	bool ok1 = 1;
	for(int i=1;i<n;i++)
	{
		bool ok2 = 0;
		for(int j=0,k=(int)s[i].size();j<k;j++)
		{
			std::string u;
			for(int x=0;x<k-j;x++)
			{	
				u += s[i][j+x];
				if(u == s[i-1])
				{
					ok2 = 1;
					break;
				}	
			}	
		}
		ok1 &= ok2;
		if(!ok1)
		break;	
	}	
	if(ok1)
	{
		std::cout<<"YES\n";
		for(int i=0;i<n;i++)
		std::cout<<s[i]<<"\n";	
	}
	else std::cout<<"NO\n";
	return 0;	
}