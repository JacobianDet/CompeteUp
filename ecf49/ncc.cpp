#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

int main(void)
{
	ll n;
	int q;
	std::cin>>n>>q;
	while(q--)
	{
		ll x, y;
		std::cin>>x>>y;
		ll a = (n * (x - 1) + y);
		if(a & 1)
		{
			a /= 2;
			a++;
		}	
		else a /= 2;
		ll b = (n * n);
		if(b & 1)
		{
			b /= 2;
			b++;
		}	
		else b /= 2;
		if((x + y) & 1)
		std::cout<<(a + b)<<"\n";
		else std::cout<<a<<"\n";
	}
	return 0;
}