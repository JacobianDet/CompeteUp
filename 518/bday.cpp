#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	ll n,m,k,l;
	std::cin>>n>>m>>k>>l;
	ll cv = std::max(k + l, m);
	if(cv % m)
	{	
		ll x = m * ((cv/m) + 1);
		if(x > n)
		std::cout<<"-1\n";	
		else std::cout<<((cv/m) + 1)<<"\n";
	}	
	else 
	{
		ll x = cv;
		if(x > n)
		std::cout<<"-1\n";	
		else std::cout<<(cv/m)<<"\n";
	}			
	return 0;	
}