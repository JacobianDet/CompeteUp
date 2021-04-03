#include <bits/stdc++.h>
#define mp std::make_pair

typedef long long ll;
typedef long double ld;

std::pair<ll, ll> ext_euclid(ll a, ll b)
{
	if(!b)
	return mp(1, 0);
	else
	{
		std::pair<ll, ll> px = ext_euclid(b, a%b);
		ll n1 = px.second;
		ll n2 = px.first - (a/b) * px.second;
		return mp(n1, n2);
	}	
}

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		ll n,m,k;
		std::cin>>n>>m>>k;
		ll z = n - (n/m)*m;
		if(z % std::__gcd(k, m) || (z == n))
		std::cout<<"-1\n";
		else
		{
			ll tv = z/std::__gcd(k, m);
			ll gc = std::__gcd(k, m);
			std::pair<ll, ll> px = ext_euclid(k, m);
			ld lx = std::max(-(ld)px.first/(ld)(m/gc), (ld)px.second/(ld)(k/gc));
			ld rx = ((ld)px.second + ((((ld)n - z)/(ld)m)/(ld)tv))/(ld)(k/gc);
			//std::cout<<px.first<<" "<<px.second<<" "<<tv<<" "<<gc<<" "<<lx<<" "<<rx<<"\n";
			if(lx >= rx)
			std::cout<<"-1\n";
			else 
			{
				ld pt = (px.first + lx * m/gc)*tv;
				std::cout<<pt<<"\n";
			}	
		}	
	}
	return 0;
}