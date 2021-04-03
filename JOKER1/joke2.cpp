#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long ll;

ll modexp(ll a, ll n)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)
		res = ((res%MOD) * (a%MOD))%MOD;
		a = ((a%MOD) * (a%MOD))%MOD;
		n >>= 1;	
	}
	return res;
}

int main(void)
{
	int T;
	std::cin>>T;
    ll s6 = modexp(6, MOD-2)%MOD;
	while(T--)
	{
		ll x,y;
		std::cin>>x>>y;
		if(y - 2)
		{	
			ll a1 = ((((((y%MOD) * ((y-1)%MOD))%MOD) * ((y-2)%MOD))%MOD) * (s6%MOD))%MOD;
			if(x - 3)
			{
				ll a2 = (((((((x-1)%MOD) * ((x-2)%MOD))%MOD) * ((x-3)%MOD))%MOD) * (s6%MOD))%MOD;
				a1 = ((a1%MOD) - (a2%MOD) + MOD)%MOD;
			}
			std::cout<<a1<<"\n";
		}		
		else std::cout<<"0\n";
	}
	return 0;
}