#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long ll;

ll factx[1000001], invf[1000001], DX[1000001];

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

void factup(void)
{
	factx[0] = 1;
	invf[0] = 1;
	DX[0] = 1;
	for(ll i=1;i<1000001;i++)
	{
		factx[i] = ((i%MOD) * (factx[i-1]%MOD))%MOD;
		invf[i] = modexp(factx[i], MOD-2)%MOD;
		if(i & 1)
		DX[i] = ((DX[i-1]%MOD) - (invf[i]%MOD) + MOD)%MOD;
		else DX[i] = ((DX[i-1]%MOD) + (invf[i]%MOD))%MOD;	
	}	
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	factup();
	int T;
	std::cin>>T;
	while(T--)
	{
		ll n,k;
		std::cin>>n>>k;
		if(k == 1)
		std::cout<<"0\n";	
		else
		{
			ll z = n/k;
			ll ans = 0;
			for(ll i=1;i<=z;i++)
			{
				ll ax = (((((((factx[n]%MOD) * (DX[n-i*k]%MOD))%MOD) * (modexp(modexp(k, i), MOD-2)%MOD))%MOD) * (invf[i]%MOD))%MOD);
				if(!(i & 1))
				ans = ((ans%MOD) - (ax%MOD) + MOD)%MOD;
				else ans = ((ans%MOD) + (ax%MOD))%MOD;	
			}	
			std::cout<<ans<<"\n";
		}	
	}
	return 0;
}