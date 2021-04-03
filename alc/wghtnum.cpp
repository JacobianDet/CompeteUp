#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long ll;

ll modexp(ll n)
{
	ll res = 1;
	ll a = 10;
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
		ll n,w;
		std::cin>>n>>w;
		ll ans = 0;
		for(int i=1;i<=9;i++)
		{
			for(int j=0;j<=9;j++)
			{
				if(j-i == w)
				ans = (ans%MOD + modexp(n-2)%MOD)%MOD;
			}	
		}	
		std::cout<<ans<<"\n";
	}
	return 0;	
}