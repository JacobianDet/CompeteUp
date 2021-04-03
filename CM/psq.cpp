#include <bits/stdc++.h>

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	std::string s;
	std::cin>>s;
	int ct = 0;
	int sb = 0, eb = 0;
	for(int i=1;i<n;i++)
	{
		if(s[i] != s[i-1])
		{	
			ct += (((eb - sb + 1) * (eb - sb + 2))/2);
			sb = i;
			eb = i;
		}
		else eb = i;		
	}	
	ct += (((eb - sb + 1) * (eb - sb + 2))/2);
	std::cout<<ct<<"\n";
	return 0;
}