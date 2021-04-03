#include <bits/stdc++.h>
#define CHOR 1000001
#define pb push_back

typedef long long ll;

ll n;
ll arr[CHOR];
ll lo[CHOR], mu[CHOR], d[CHOR], ct[CHOR], ans[CHOR];

void mob_sling(void)
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
	for(ll i=0;i<n;i++)
	ct[arr[i]]++;
	for(ll i=1;i<CHOR;i++)
	{
		for(ll j=i;j<CHOR;j+=i)
		d[i] += ct[j];	
	}	
	for(ll i=1;i<CHOR;i++)
	ans[i] = ans[i-1] + mu[i] * ((((d[i]) * (d[i]-1))/2) * (d[i]-2))/3; 	
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::cin>>n;
	for(ll i=0;i<n;i++)
	std::cin>>arr[i];
	mob_sling();
	std::cout<<ans[CHOR-1]<<"\n";
	return 0;	
}