#include <bits/stdc++.h>
#define CHOR 100001
#define MOD 1000000007

typedef long long ll;

ll phi[CHOR], f[CHOR];

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

void phi_calc(ll k)
{
	for(ll i=1;i<CHOR;i++)
	phi[i] = i;
	for(ll i=2;i<CHOR;i++)
	{
		if(phi[i] == i)
		{
			for(ll j=i;j<CHOR;j+=i)
			phi[j] = ((((phi[j]%MOD) * (modexp(i, MOD-2)%MOD))%MOD) * ((i%MOD - 1 + MOD)%MOD))%MOD;
		}			
	}
	for(ll i=1;i<CHOR;i++)
	{
		for(ll j=i;j<CHOR;j+=i)
		f[j] = f[j]%MOD + ((modexp(i, k)%MOD) * (phi[j/i]%MOD))%MOD;	
	}	
	for(ll i=1;i<CHOR;i++)
	f[i] = (f[i-1]%MOD + f[i]%MOD)%MOD;	
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll k,T;
	std::cin>>k>>T;
	phi_calc(k);
	while(T--)
	{
		ll l,r;
		std::cin>>l>>r;
		std::cout<<((f[r]%MOD - f[l-1]%MOD + MOD)%MOD)<<"\n";
	}	
	return 0;
}