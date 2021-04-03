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
	ll la, ra, ta, lb, rb, tb;
	std::cin>>la>>ra>>ta>>lb>>rb>>tb;
	if(abs((la - lb) + (tb - ta)) % std::__gcd(ta, tb))
	{
		if(lb <= la && ra <= rb)
		std::cout<<(ra - la + 1)<<"\n";
		else if(la <= lb && rb <= ra)
		std::cout<<(rb - lb + 1)<<"\n";
		else 
		{
			if(la <= lb)
			std::cout<<std::max(0LL, std::max(ra - lb + 1, rb - la - ta + 1))<<"\n";
			else std::cout<<std::max(0LL, std::max(rb - la + 1, ra - lb - tb + 1))<<"\n";
		}	
	}
	else
	{
		ll z = ((la - lb) + (tb - ta))/std::__gcd(ta, tb);
		std::pair<ll, ll> p = ext_euclid(tb, ta);
		ll x = p.first * z;
		ll y = -p.second * z;
		ll ax = la + (y - 1)*ta;
		ll bx1 = ax + (ra - la);
		ll bx2 = ax + (rb - lb);
		std::cout<<(std::min(bx1, bx2) - ax + 1)<<"\n";	
	}	
	return 0;
}