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
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	while(T--)
	{
		ll n;
		std::cin>>n;
		if(n == 1)
		std::cout<<"4\n";
		else if(n == 2)
		std::cout<<"16\n";
		else if(n == 3)
		std::cout<<"48\n";
		else
		{
			ll zf = ((((16LL%MOD) * (modexp(3, n-2)%MOD))%MOD) - (((((8LL%MOD) * ((n-3)%MOD))%MOD) * (modexp(3, n-4)%MOD))%MOD) + MOD)%MOD;
			std::cout<<zf<<"\n"; 
		}	
	}
	return 0;
}