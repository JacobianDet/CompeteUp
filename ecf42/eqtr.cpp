#include <bits/stdc++.h>

typedef long long ll;

ll pref[200001];

int main(void)
{
	ll n;
	std::cin>>n;
	for(ll i=1;i<=n;i++)
	{
		ll t;
		std::cin>>t;
		pref[i] = pref[i-1] + t;
	}	
	for(ll i=1;i<=n;i++)
	{
		if(pref[i] >= ceil(pref[n]/2))
		{
			std::cout<<i<<"\n";
			break;
		}	
	}	
	return 0;
}