#include <bits/stdc++.h>

int main(void)
{
	int n;
	std::cin>>n;
	std::string s;
	std::cin>>s;
	int ct = 0;
	for(int i=0;i<n; )
	{
		if(i != n-1 && s[i] == 'R' && s[i+1] == 'U')
		{
			ct++;
			i += 2;
		}
		else if(i != n-1 && s[i] == 'U' && s[i+1] == 'R')
		{
			ct++;
			i += 2;
		}	
		else 
		{
			i++;
			ct++;
		}	
	}
	std::cout<<ct<<"\n";
	return 0;	
}