#include <bits/stdc++.h>
#define CHOR 100001

typedef long long ll;

ll lo[CHOR], mu[CHOR], f[CHOR], ans[CHOR], arr[CHOR], d[CHOR], ct[CHOR];

void chorchor(void)
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
		ll j=i;
		while(lo[j/lo[j]] != lo[j])
		j /= lo[j];
		if(j != 1)
		mu[i] = 0;
		else mu[i] = -1*mu[i/lo[i]];	
	}	
	return;
}

void fct(ll n, ll k)
{
	memset(f, 0, sizeof(f));
	memset(ans, 0, sizeof(ans));
	memset(d, 0, sizeof(d));
	memset(ct, 0, sizeof(ct));
	for(ll i=k;i<CHOR;i++)
	{
		for(ll j=i;j<CHOR;j+=i)
		f[j] += mu[j/i];	
	}	
	for(ll i=0;i<n;i++)
	ct[arr[i]]++;
	for(ll i=1;i<CHOR;i++)
	{
		for(ll j=i;j<CHOR;j+=i)
		d[i] += ct[j];	
	}	
	for(ll i=1;i<CHOR;i++)
	ans[i] = ans[i-1] + f[i]*(((d[i]) * (d[i]-1))/2);
	return;
}

int main(void)
{
	chorchor();
	ll T;
	std::cin>>T;
	while(T--)
	{
		ll n,k;
		std::cin>>n>>k;
		for(ll i=0;i<n;i++)
		std::cin>>arr[i];
		fct(n, k);	
		std::cout<<ans[CHOR-1]<<"\n";
	}	
	return 0;
}