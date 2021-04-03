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
	ll x,k,b=0;
	std::cin>>x>>k;
	k++;
	if(x)
	b = ((((modexp(2, k)%MOD) * (x%MOD))%MOD) - (modexp(2, k-1)%MOD) + (1%MOD) + MOD)%MOD;
	std::cout<<b<<"\n";
	return 0;
}