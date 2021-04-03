#include <bits/stdc++.h>
#define CHOR 100001
#define MOD 163577857

typedef long long ll;

ll fct[CHOR];

void factup(void)
{
	fct[0] = 1;
	for(int i=1;i<CHOR;i++)
	fct[i] = ((i%MOD) * (fct[i-1]%MOD))%MOD;
	return;	
}

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
	factup();
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	{
		if((i == 1) || (i == n))
		std::cout<<"1 ";
		else
		{
			ll ax = modexp(fct[i-1], MOD-2)%MOD;
			ll bx = modexp(fct[n-i+1], MOD-2)%MOD;
			ll ans = ((fct[n]%MOD) * (((ax%MOD) * (bx%MOD))%MOD))%MOD;
			std::cout<<ans<<" ";
		}	
	}
	std::cout<<"\n";
	return 0;
}