#include <bits/stdc++.h>

int main(void)
{
	std::string s;
	std::cin>>s;
	int p = 0,d = 0;
	for(int i=0,j=(int)s.size();i<j;i++)
	{
		if(s[i] == '-')
		d++;
		else p++;	
	}	
	if(!p || !(d % p))
	std::cout<<"YES\n";
	else std::cout<<"NO\n";
	return 0;	
}