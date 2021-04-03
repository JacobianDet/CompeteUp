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
	while(T--)
	{
		ll n,m,q,k;
		std::cin>>n>>m>>q>>k;
		if((m < q+1) || (n == 1))
		std::cout<<"0\n";
		else
		{	
			ll a1 = 0, a2 = 0, a3 = 0;
			a1 = modexp(q+1, n)%MOD;
			if(q >= 0)
			a2 = ((2%MOD) * (modexp(q, n)%MOD))%MOD;
			if(q >= 1)
			a3 = modexp(q-1, n)%MOD;
			ll ans = (((m-q)%MOD) * (((((a1%MOD) - (a2%MOD) + MOD)%MOD) + (a3%MOD))%MOD))%MOD;
			std::cout<<ans<<"\n"; 
		}	
	}
	return 0;
}