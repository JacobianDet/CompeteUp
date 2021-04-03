#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	while(n--)
	{
		ll p,q,b;
		std::cin>>p>>q>>b;
		if(!(p % q))
		std::cout<<"Finite\n";
		else
		{
			q /= std::__gcd(p, q);
			while(std::__gcd(q, b) != 1)
			{
				ll x = std::__gcd(q, b);
				while(!(q % x))
				q /= x;	
			}
			if(q == 1)
			std::cout<<"Finite\n";
			else std::cout<<"Infinite\n";	
		}	
	}	
	return 0;
}