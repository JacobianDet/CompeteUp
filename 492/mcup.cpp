#include <bits/stdc++.h>
#define CHOR 100001

typedef long long ll;

ll arr[CHOR];

ll bs1(ll a, ll n)
{
	ll lo = 1;
	ll hi = 1000000000;
	while(lo < hi)
	{
		ll mid = lo + (hi - lo)/2;
		if(arr[a] - (a + (mid-1)*n) <= 0)
		hi = mid;
		else lo = mid + 1;	
	}
	return (a + (lo-1)*n);	
}

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	ll ans = 1000000000000;
	for(int i=0;i<n;i++)
	ans = std::min(ans, bs1(i, n));
	std::cout<<(ans%n + 1)<<"\n";
	return 0;
}