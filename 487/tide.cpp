#include <bits/stdc++.h>

int main(void)
{
	int n,p;
	std::cin>>n>>p;
	std::string s;
	std::cin>>s;
	bool ok = 0;
	for(int i=0;i<n-p;i++)
	{
		if((s[i] == '.') || (s[i+p] == '.') || (s[i] != s[i+p]))
		{
			ok = 1;
			if((s[i] == '.') && (s[i+p] == '.'))
			{
				s[i] = '0';
				s[i+p] = '1';
			}	
			else if(s[i] == '.')
			{
				if(s[i+p] == '1')
				s[i] = '0';
				else s[i] = '1';	
			}	
			else if(s[i+p] == '.')
			{
				if(s[i] == '1')
				s[i+p] = '0';
				else s[i+p] = '1';	
			}
			break;
		}
	}
	if(!ok)
	std::cout<<"No\n";
	else 
	{
		for(int i=0;i<n;i++)
		{
			if(s[i] == '.')
			s[i] = '0';	
		}	
		std::cout<<s<<"\n";
	}	
	return 0;
}