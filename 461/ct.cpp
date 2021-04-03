#include <bits/stdc++.h>
#define ll long long

int main(void)
{
	ll x,y;
	std::cin>>x>>y;
	if(!x && !(y-1))
	std::cout<<"YES\n";
	else if((x && !(y-1)) || !y)
	std::cout<<"NO\n";	
	else if((y-1) > x)
	std::cout<<"NO\n";
	else if((y-1) & 1)
	{
		if(x & 1)
		std::cout<<"YES\n";
		else std::cout<<"NO\n";	
	}	
	else 
	{
		if(x & 1)
		std::cout<<"NO\n";
		else std::cout<<"YES\n";	
	}	
	return 0;
}