#include <bits/stdc++.h>

bool checkpal(std::string s)
{
	int n = (int)s.size();
	bool ok = 1;
	for(int i=0;i<(n>>1);i++)
	{
		if(s[i] != s[n-i-1])
		{
			ok = 0;
			break;
		}	
	}
	return ok;	
}

int main(void)
{
	std::string s;
	std::cin>>s;
	if(!checkpal(s))
	std::cout<<s.size()<<"\n";
	else
	{
		int mc = 0;
		for(int i=0,j=(int)s.size();i<j;i++)
		{
			std::string x;
			for(int k=0;k<j-i;k++)
			{
				x += s[i+k];
				if(!checkpal(x))
				mc = std::max(mc, (int)x.size());
			}	
		}
		std::cout<<mc<<"\n";	
	}	
	return 0;
}