#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll n;
	std::cin>>n;
	if(n == 2)
	std::cout<<"1\n";
	else if(n == 3)
	std::cout<<"2\n";
	else
	{
		ll a = 2, b = 3;
		ll x = 2;
		while(a + b <= n)	
		{
			ll tmp = b;
			b = a + b;
			a = tmp;
			x++;
		}
		std::cout<<x<<"\n";
	}	
	return 0;
}