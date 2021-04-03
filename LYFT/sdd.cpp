#include <bits/stdc++.h>

typedef long long ll;

bool pfind(ll n)
{
	for(ll i=2;i*i<=n;i++)
	{
		if(!(n % i))
		return 0;	
	}	
	return 1;
}

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		ll a,b;
		std::cin>>a>>b;
		if((a - b) == 1)
		{
			if(pfind(a+b))
			std::cout<<"YES\n";
			else std::cout<<"NO\n";	
		}
		else std::cout<<"NO\n";	
	}
	return 0;
}