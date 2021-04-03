#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long ll;

ll memo[(1<<21)];

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
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	{
		int t;
		std::cin>>t;
		memo[t]++;
	}	
	for(int p=0;p<21;p++)
	{	
		for(int mask=((1<<21)-1); mask>=0; mask--)
		{
			if(!(mask & (1<<p)))
			memo[mask] += memo[mask ^ (1<<p)];	
		}
	}
	ll ans = 0;
	for(int mask=0; mask<(1<<21); mask++)
	{
		int z = __builtin_popcount(mask);
		if(z & 1)
		ans = ((ans%MOD) - ((modexp(2, memo[mask]) - 1)%MOD) + MOD)%MOD;
		else ans = ((ans%MOD) + ((modexp(2, memo[mask]) - 1)%MOD))%MOD;
	}	
	std::cout<<ans<<"\n";
	return 0;
}