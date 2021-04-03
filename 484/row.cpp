#include <bits/stdc++.h>

int main(void)
{
	int n;
	std::cin>>n;
	std::string s;
	std::cin>>s;
	bool ok = 1;
	for(int i=1;i<n;i++)
	{
		if(s[i] == '1')
		{
			if(s[i-1] == '1')
			{
				ok = 0;
				break;
			}	
		}	
	}
	if(ok)
	{
		int x = 0;
		for(int i=0;i<n;i++)
		{
			if(s[i] == '0')
			{
				bool ox = 1;
				s[i] = '1';
				for(int j=1;j<n;j++)
				{
					if(s[j] == '1')
					{
						if(s[j-1] == '1')
						{
							ox = 0;
							s[i] = '0';
							break;
						}
					}	
				}
				if(ox)
				x++;	
			}	
		}
		if(!x)
		std::cout<<"Yes\n";
		else std::cout<<"No\n";	
	}
	else std::cout<<"No\n";	
	return 0;
}