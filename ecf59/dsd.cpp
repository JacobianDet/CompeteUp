#include <bits/stdc++.h>

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n;
		std::cin>>n;
		std::string s;
		std::cin>>s;
		if(n == 2)
		{
			if(s[0] >= s[1])
			std::cout<<"NO\n";
			else 
			{
				std::cout<<"YES\n2\n";
				std::cout<<s[0]<<" ";
				for(int i=1;i<n;i++)
				std::cout<<s[i];
				std::cout<<"\n";
			}	
		}
		else
		{
			std::cout<<"YES\n2\n";
			std::cout<<s[0]<<" ";
			for(int i=1;i<n;i++)
			std::cout<<s[i];
			std::cout<<"\n";
		}
	}
	return 0;
}	
