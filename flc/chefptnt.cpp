#include <bits/stdc++.h>

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n,m,x,k;
		std::cin>>n>>m>>x>>k;
		std::string s;
		std::cin>>s;
		int o=0,e=0;
		for(int i=0;i<k;i++)
		{
			if(s[i] == 'O')
			o++;
			else e++;	
		}	
		for(int i=1;(i<=m && n);i++)
		{
			if(i & 1)
			{
				if(o >= x)
				{
					if(n >= x)
					n -= x;
					else n = 0;
					o -= x;
				}	
				else 
				{	
					if(n >= o)
					n -= o;
					else n = 0;
					o = 0;
				}	
			}	
			else
			{
				if(e >= x)
				{
					if(n >= x)
					n -= x;
					else n = 0;
					e -= x;
				}	
				else 
				{	
					if(n >= e)
					n -= e;
					else n = 0;
					e = 0;
				}	
			}	
		}
		if(!n)
		std::cout<<"yes\n";
		else std::cout<<"no\n";	
	}	
	return 0;
}