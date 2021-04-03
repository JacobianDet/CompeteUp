#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long ll;

ll factup[200001];
ll inv_fup[200001];

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

void factx(void)
{
	factup[0] = 1;
	inv_fup[0] = 1;
	for(ll i=1;i<200001;i++)
	{	
		factup[i] = ((factup[i-1]%MOD) * (i%MOD))%MOD;
		inv_fup[i] = modexp(factup[i], MOD-2)%MOD;
	}	
	return;
}

int main(void)
{
	freopen("H3.in", "r", stdin);
	freopen("H3.txt", "w", stdout);
	factx();
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		ll n,m;
		std::cin>>n>>m;
		ll ans = 0;
		for(ll i=0;i<=m;i++)
		{
			ll f1 = ((factup[m]%MOD) * (((inv_fup[i]%MOD) * (inv_fup[m-i]%MOD))%MOD))%MOD;
			ll f2 = factup[2*n-i]%MOD;
			ll f3 = modexp(2, i)%MOD;
			if(i & 1)
			ans = ((ans%MOD) - (((((f1%MOD) * (f2%MOD))%MOD) * (f3%MOD))%MOD) + MOD)%MOD;
			else ans = ((ans%MOD) + (((((f1%MOD) * (f2%MOD))%MOD) * (f3%MOD))%MOD))%MOD;
		}
		std::cout<<"Case #"<<t<<": "<<ans<<"\n";	
	}
	return 0;
}