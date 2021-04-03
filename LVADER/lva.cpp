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

ll factx[500001], inv_fx[500001];

void factup(void)
{
	factx[0] = 1;
	inv_fx[0] = 1;
	for(ll i=1;i<500001;i++)
	{
		factx[i] = ((i%MOD) * (factx[i-1]%MOD))%MOD;
		inv_fx[i] = modexp(factx[i], MOD-2)%MOD;
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
	for(int t=1;t<=T;t++)
	{
		ll x1,y1,x2,y2;
		std::cin>>x1>>y1>>x2>>y2;
		int n = x2 - x1;
		int m = y2 - y1;
		std::cout<<"Case "<<t<<": ";
		if(!n || !m)
		std::cout<<"1\n";
		else
		{
			ll ax = 0;
			for(ll i=0;i<=std::min(n, m);i++)
			ax = ((((ax%MOD) + (((((((factx[n+m-i]%MOD) * (inv_fx[n-i]%MOD))%MOD) * (inv_fx[m-i]%MOD))%MOD) * (inv_fx[i]%MOD))%MOD))%MOD)%MOD);
			std::cout<<ax<<"\n"; 
		}	
	}
	return 0;
}