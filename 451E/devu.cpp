#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long ll;

ll f[21];

ll modexp(ll a, ll n)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)
		res = ((res%MOD) * (a%MOD));
		a = ((a%MOD) * (a%MOD));
		n >>= 1;	
	}
	return res;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll n,s;
	std::cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		std::cin>>f[i];
		if(f[i] > s)
		f[i] = s;
	}
	ll ans = 0;
	for(int i=0;i<(1<<n);i++)
	{
		ll sx = 0;
		for(int j=0;j<n;j++)
		{
			if(i & (1<<j))
			sx += (f[j] + 1);	
		}
		if((n + s - sx - 1) >= 0)
		{
			ll a1 = 1, a2 = 1;
			for(ll j=1;j<n;j++)
			{
				a1 = ((a1%MOD) * ((s - sx + j)%MOD))%MOD;
				a2 = ((a2%MOD) * (j%MOD))%MOD;
			}	
			a2 = modexp(a2, MOD-2)%MOD;
			if(__builtin_popcount(i) & 1)
			ans = ((ans%MOD) - (((a1%MOD) * (a2%MOD))%MOD) + MOD)%MOD;
			else ans = ((ans%MOD) + (((a1%MOD) * (a2%MOD))%MOD))%MOD;
		}	
	}
	std::cout<<ans<<"\n";
	return 0;	
}