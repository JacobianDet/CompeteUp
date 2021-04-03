#include <bits/stdc++.h>

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n;
		std::string s;
		std::cin>>n>>s;
		bool ok = 0;
		for(int i=0;i<n/2;i++)
		{
			if(abs(s[i] - s[n-1-i]) == 2 || (s[i] == s[n-1-i]))
			continue;
			else
			{
				ok = 1;
				break;
			}	
		}	
		if(!ok)
		std::cout<<"YES\n";
		else std::cout<<"NO\n";	
	}
	return 0;
}