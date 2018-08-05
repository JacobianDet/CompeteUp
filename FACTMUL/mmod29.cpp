#include <bits/stdc++.h>

typedef long long ll;

ll modexp(ll a, ll n)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)
		res = ((res%29) * (a%29))%29;
		a = ((a%29) * (a%29))%29;
		n >>= 1;	
	}	
	return res;
}

int main(void)
{
	int x;
	std::cin>>x;
	while(x)
	{
		ll z1 = ((modexp(2, 2*x+1)%29) - (1%29) + 29)%29;
		ll z2 = ((((modexp(3, x+1)%29) - (1%29) + 29)%29) * (modexp(2, 27)%29))%29;
		ll z3 = ((((modexp(167, x+1)%29) - (1%29) + 29)%29) * (modexp(166, 27)%29))%29;
		std::cout<<(((((z1%29) * (z2%29))%29) * (z3%29))%29)<<"\n";
		std::cin>>x;
	}	
	return 0;
}