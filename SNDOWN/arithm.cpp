#include <bits/stdc++.h>
#define mp std::make_pair

typedef long long ll;

std::pair<ll, ll> ext_euclid(ll a, ll b)
{
	if(!b)
	return mp(1, 0);
	else
	{
		std::pair<ll, ll> p = ext_euclid(b, a%b);
		ll ix = p.first;
		ll iy = p.second;
		ll x = iy;
		ll y = ix - (a/b)*iy;
		return mp(x, y);
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	while(T--)
	{
		ll n,c;
		std::cin>>n>>c;
		if((2*c) % n)
		std::cout<<"No\n";
		else
		{
			if(((2*c/n) - (n-1) > 0) && !(((2*c/n) - (n-1)) & 1))
			std::cout<<"Yes\n";
			else if(((2*c/n) - 2*(n-1) > 0) && !(((2*c/n) - 2*(n-1)) & 1))
			std::cout<<"Yes\n";
			else std::cout<<"No\n";	
		}
	}	
	return 0;
}