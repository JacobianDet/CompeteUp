#include <bits/stdc++.h>
#define pb push_back

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n;
		std::cin>>n;
		int o = 0, e = 0;
		for(int i=0;i<n;i++)
		{
			int t;
			std::cin>>t;
			if(t & 1)
			o++;
			else e++;
		}	
		if(!o && e)
		std::cout<<"1\n";
		else if(!e)
		{
			if(o == 1 || !(o & 1))
			std::cout<<"1\n";
			else std::cout<<"2\n";	
		}	
		else
		{
			if(o & 1)
			std::cout<<"2\n";
			else std::cout<<"1\n";	
		}
	}
	return 0;	
}