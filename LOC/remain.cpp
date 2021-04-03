#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		ll n,m;
		std::cin>>n>>m;
		if((n % m) & 1)
		std::cout<<"ODD\n";
		else std::cout<<"EVEN\n";	
	}	
	return 0;
}