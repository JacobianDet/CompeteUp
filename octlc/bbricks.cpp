#include <bits/stdc++.h>
#define MOD 1000000007LL

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
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	while(T--)
	{
		ll n,k;
		std::cin>>n>>k;
		if(n < k)
		std::cout<<"0\n";
		else
		{
			ll a1 = 1;
			ll a2 = 1;
			ll a3 = 1;
			ll a4 = 1;
			ll t2 = 1;
			ll st = 0;
			for(ll i=1;((i<=k) && ((n - k + 2 - i) > 0));i++)
			{
				a1 = ((a1%MOD) * ((n - k + 2 - i)%MOD))%MOD;
				a2 = ((a2%MOD) * (i%MOD))%MOD;
				if(i == 1)
				{
					a3 = 1;
					a4 = 1;
				}	
				else
				{
					a3 = ((a3%MOD) * ((k-i+1)%MOD))%MOD;
					a4 = ((a4%MOD) * ((i-1)%MOD))%MOD;
				}
				t2 = ((t2%MOD) * ((2LL)%MOD))%MOD;
				ll px = modexp(a2, MOD-2)%MOD;
				ll qx = modexp(a4, MOD-2)%MOD;
				ll at = ((a3%MOD) * (qx%MOD))%MOD;
				ll bt = ((((((t2%MOD) * (a1%MOD))%MOD) * (px%MOD))%MOD) * (at%MOD))%MOD;
				st = ((st%MOD) + (bt%MOD))%MOD;
			}	
			std::cout<<st<<"\n";
		}	
	}
	return 0;
}