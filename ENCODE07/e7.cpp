#include <bits/stdc++.h>
#define CHOR 100001

typedef long long ll;

ll lo[CHOR], mu[CHOR];

void mob_sling(void)
{
	for(ll i=1;i<CHOR;i++)
	{
		lo[i] = i;
		mu[i] = 1;
	}	
	for(ll i = 2;i<CHOR;i++)
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
		ll j=i;
		while(lo[j/lo[j]] != lo[j])
		j /= lo[j];
		if(j != 1)
		mu[i] = 0;
		else mu[i] = -1*mu[i/lo[i]];	
	}	
	return;
}

int main(void)
{
	mob_sling();
	ll T;
	std::cin>>T;
	while(T--)
	{
		ll n;
		std::cin>>n;
		ll res = n*n;
		for(ll i=2;i<=n;i++)
		{
			ll ans = 0;
			for(ll j=i;j<=n;j+=i)
			{
				if(mu[j] != 0)
				ans++;
			}	
			res += (ans * ans * mu[i]);
		}	
		std::cout<<res<<"\n";
	}	
	return 0;
}