#include <bits/stdc++.h>
#define CHOR 1000001

typedef long long ll;

ll lo[CHOR], mu[CHOR], f[CHOR], lc[CHOR];

void mob_calc(void)
{
	for(ll i=1;i<CHOR;i++)
	{
		lo[i] = i;
		mu[i] = 1;
	}	
	for(ll i=2;i<CHOR;i++)
	{
		if(lo[i] == i)
		{	
			for(ll j=i*i;j<CHOR;j+=i)
			{
				if(lo[j] == j)
				lo[j] = i;	
			}	
		}	
	}	
	for(ll i=2;i<CHOR;i++)
	{
		ll j = i;
		while(lo[j/lo[j]] != lo[j])
		j /= lo[j];	
		if(j != 1)
		mu[i] = 0;
		else mu[i] = -1*mu[i/lo[i]];	
	}	
	for(ll i=1;i<CHOR;i++)
	{
		for(ll j=i;j<CHOR;j+=i)
		f[j] = f[j] + i*mu[i];
	}	
	for(ll i=1;i<CHOR;i++)
	{
		for(ll j=i;j<CHOR;j+=i)
		lc[j] += (j*(j/i)*f[i]*(i+j)/(2*i));	
	}	
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	mob_calc();
	ll T;
	std::cin>>T;
	while(T--)
	{
		ll n;
		std::cin>>n;
		std::cout<<lc[n]<<"\n";
	}	
	return 0;
}