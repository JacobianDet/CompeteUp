#include <bits/stdc++.h>

int main(void)
{
	std::string s;
	std::cin>>s;
	int n = (int)s.size();
	if(n == 2)
	{
		if(s != "11")
		std::cout<<"-1\n";
		else std::cout<<"1 2\n";	
	}	
	else
	{
		int ct = 0;	
		bool ok = 1;
		bool sz = 0;
		for(int i=0;i<n/2;i++)
		{
			if(s[i] == '1' && s[n-2-i] == '1')
			{	
				if(sz)
				{
					ok = 0;
					break;
				}	
				ct++;
			}
			else if(s[i] == '1' || s[n-2-i] == '1')
			{
				ok = 0;
				break;
			}	
			else 
			{
				if(!i)
				{	
					ok = 0;
					break;
				}	
				if(!sz)
				sz = 1;
			}	
		}	
		if(s[n-1] == '1')
		ok = 0;	
		if(!ok)
		std::cout<<"-1\n";
		else 
		{
			int ec1 = n - ct;
			for(int i=1;i<=ec1;i++)
			std::cout<<"1 "<<i+1<<"\n";
			for(int i=ec1+1;i<n;i++)
			std::cout<<i<<" "<<i+1<<"\n";	
		}	
	}
	return 0;
}