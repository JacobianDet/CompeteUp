#include <bits/stdc++.h>
#define ll long long
#define pb push_back

int main(void)
{
	ll T;
	std::cin>>T;
	for(ll t=0;t<T;t++)
	{
		ll n,k;
		std::cin>>n>>k;
		ll a[n];
		std::vector<ll> sign;
		for(ll i=0;i<n;i++)
		{	
			std::cin>>a[i];
			if(a[i] < 0)
			sign.pb(i);
		}
		ll msum = 0;
		if(sign.size() == 0)
		{
			for(ll i=0;i<n;i++)
			msum += a[i];
			msum *= k;	
		}				
		
		std::cout<<msum<<"\n";
	}	
	return 0;
}