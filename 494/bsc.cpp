#include <bits/stdc++.h>

std::string s[201];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int a,b,x;
	std::cin>>a>>b>>x;
	int xa = a, xb = b;
	if(xa > xb)
	{
		for(int i=0;i<=x;i++)
		{
			if(i & 1)
			{
				s[i] = '1';
				b--;
			}	
			else
			{
				s[i] = '0';
				a--;
			}
		}
		while(a--)
		s[0] += '0';
		while(b--)
		s[1] += '1';	
	}	
	else
	{
		for(int i=0;i<=x;i++)
		{
			if(i & 1)
			{
				s[i] = '0';
				a--;
			}
			else
			{
				s[i] = '1';
				b--;
			}
		}
		while(a--)
		s[1] += '0';
		while(b--)
		s[0] += '1';	
	}
	for(int i=0;i<=x;i++)
	std::cout<<s[i];
	std::cout<<"\n";	
	return 0;	
}