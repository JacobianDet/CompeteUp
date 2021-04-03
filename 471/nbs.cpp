#include <bits/stdc++.h>

int main(void)
{
	int ft[26];
	memset(ft,0,sizeof(ft));
	std::string s;
	std::cin>>s;
	int n = (int)s.size();
	if(n <= 3)
	{
		std::cout<<"No\n";
		return 0;
	}	
	for(int i=0;i<n;i++)
	ft[s[i]-97]++;
	int dt = 0;	
	for(int i=0;i<26;i++)
	{
		if(ft[i])
		dt++;	
	}
	int a=0,b=0;
	if(dt == 2)
	{	
		for(int i=0;i<26;i++)
		{
			if(ft[i])
			{
				if(!a)
				a = ft[i];
				else b = ft[i];	
			}	
		}
	}
	if((dt == 3) || (dt == 4) || ((dt == 2) && (a > 1 && b > 1)))
	std::cout<<"Yes\n";
	else std::cout<<"No\n";
	return 0;
}