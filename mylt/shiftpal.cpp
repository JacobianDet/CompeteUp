#include <bits/stdc++.h>

bool checkpal(std::string s)
{
	bool ok = 1;
	for(int i=0,j=(int)s.size();i<(j>>1);i++)
	{
		if(s[i] != s[j-i-1])
		{
			ok = 0;
			break;
		}	
	}
	return ok;
}

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		std::string s;
		std::cin>>s;
		int ans = 0;
		if(checkpal(s))
		ans++;	
		for(int i=1,j=(int)s.size();i<j;i++)
		{
			std::string p = s.substr(1, j-1);
			s = p + s[0];
			if(checkpal(s))
			ans++;	
		}
		std::cout<<ans<<"\n";	
	}	
	return 0;
}