#include <bits/stdc++.h>
#define MOD1 109546051211LL
#define MOD2 186583
#define MOD3 587117

typedef long long ll;

ll fact1[MOD2+1], fact2[MOD3+1];

void prec(void)
{
	for(int i=0;i<MOD2+1;i++)
	fact1[i] = 1;
	for(int i=0;i<MOD3+1;i++)
	fact2[i] = 1;
	for(int i=1;i<MOD2+1;i++)
	fact1[i] = ((fact1[i-1]%MOD2) * (i%MOD2))%MOD2;
	for(int i=1;i<MOD3+1;i++)
	fact2[i] = ((fact2[i-1]%MOD3) * (i%MOD3))%MOD3;
	return; 	
}

ll modexp(ll a, ll n, ll mv)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)
		res = ((res%mv) * (a%mv))%mv;
		a = ((a%mv) * (a%mv))%mv;
		n >>= 1;	
	}	
	return res;
}

int main(void)
{
	prec();
	int n;
	std::cin>>n;
	ll z1 = 1;
	ll z2 = 1;
	if(n >= MOD3)
	{
		z1 = 0;
		z2 = 0;
	}	
	else if(n < MOD2)
	{
		for(int i=1;i<=n;i++)
		{	
			z1 = ((z1%MOD2) * (fact1[i]%MOD2))%MOD2;
			z2 = ((z2%MOD3) * (fact2[i]%MOD3))%MOD3;
		}		
	}
	else
	{
		z1 = 0;
		for(int i=1;i<=n;i++)
		z2 = ((z2%MOD3) * (fact2[i]%MOD3))%MOD3;	
	}	
	ll z = ((((((z1%MOD1) * (MOD3%MOD1))%MOD1) * (modexp(MOD3, MOD2-2, MOD2)%MOD1))%MOD1) + (((((z2%MOD1) * (MOD2%MOD1))%MOD1) * (modexp(MOD2, MOD3-2, MOD3)%MOD1))%MOD1))%MOD1;
	std::cout<<z<<"\n";
	return 0; 
}