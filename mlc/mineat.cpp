#include <bits/stdc++.h>

typedef long long ll;

ll arr[100001];

ll binx(ll n, ll h)
{
	ll lo = 1;
	ll hi = 1000000000;
	while(lo < hi)
	{
		ll mid = lo + (hi-lo)/2;
		ll ctr = 0;
		for(ll i=0;i<n;i++)
		ctr += ceil((double)arr[i]/mid);
		if(ctr <= h)
		hi = mid;
		else lo = mid + 1;	
	}	
	return lo;
}

int main(void)
{
	ll T;
	std::cin>>T;
	while(T--)
	{
		ll n,h;
		std::cin>>n>>h;
		for(ll i=0;i<n;i++)
		std::cin>>arr[i];
		ll ans = binx(n, h);
		std::cout<<ans<<"\n";	
	}	
	return 0;
}