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
	ll Q;
	std::cin>>Q;
	while(Q--)
	{
		ll n,t;
		std::cin>>n>>t;
		ll p1 = 1, p2 = 1;
		for(ll i=1;i<=t+1;i++)
		{
			p1 = ((p1 % MOD) * ((n%MOD + i%MOD)%MOD))%MOD;
			p2 = ((p2 % MOD) * (i % MOD))%MOD;
		}
		ll ans = ((((p1 % MOD) - (p2 % MOD) + MOD)%MOD) * (modexp(t+1, MOD-2)%MOD))%MOD;
		std::cout<<ans<<"\n";
	}	
	return 0;
}