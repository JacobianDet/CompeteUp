#include <bits/stdc++.h>
#define MOD1 1000000007
#define MOD2 500000003
#define CHOR 100001

typedef long long ll;

ll fact1[(CHOR<<1LL)];
ll fact2[(CHOR<<1LL)];

void CRTUP(void)
{
	for(ll i=0;i<(CHOR<<1LL);i++)
	{	
		fact1[i] = 1;
		fact2[i] = 1;
	}	
	for(ll i=1;i<(CHOR<<1LL);i++)
	{	
		fact1[i] = ((fact1[i-1]%MOD2) * (i%MOD2))%MOD2;
		fact2[i] = ((fact2[i-1]%2) * (i%2))%2;
	}	
	return;	
}

ll modexp(ll a, ll n, ll mv)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)
		res = ((res%mv)	* (a%mv))%mv;
		a = ((a%mv) * (a%mv))%mv;
		n >>= 1;
	}	
	return res;
}

int main(void)
{
	CRTUP();
	int T;
	std::cin>>T;
	while(T--)
	{
		ll a,b,n;
		std::cin>>a>>b>>n;
		ll z1 = (((((fact1[(n<<1LL)]%MOD2) * (modexp(fact1[n], MOD2-2, MOD2)%MOD2))%MOD2) * (modexp(fact1[n], MOD2-2, MOD2))%MOD2))%MOD2;
		ll z2 = (((((fact2[(n<<1LL)]%2) * (modexp(fact2[n], 0, 2)%2))%2) * (modexp(fact2[n], 0, 2))%2))%2;
		ll z3 = modexp(z1, b, MOD2);
		ll z4 = modexp(z2, b, 2);
		ll p = ((((((z3%(MOD1-1)) * (2%(MOD1-1)))%(MOD1-1)) * (modexp(2, MOD2-2, MOD2)%(MOD1-1)))%(MOD1-1)) + (((((z4%(MOD1-1)) * (MOD2%(MOD1-1)))%(MOD1-1)) * (modexp(MOD2, 0, 2)%(MOD1-1)))%(MOD1-1)))%(MOD1-1);
		std::cout<<modexp(a, p, MOD1)%MOD1<<"\n";
	}
	return 0;	
}