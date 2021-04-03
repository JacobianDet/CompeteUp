#include <bits/stdc++.h>

typedef long long ll;

ll arr[200001];
ll n;

ll bs(ll y)
{
	ll lo = 1;
	ll hi = n;
	while(lo < hi)
	{
		ll mid = lo + (hi -lo)/2;
		if(arr[mid] >= y)
		hi = mid;
		else lo = mid+1;	
	}	
	return lo;	
}

int main(void)
{
	ll m;
	std::cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{	
		std::cin>>arr[i];
		arr[i] += arr[i-1];
	}	
	ll b[m];
	for(ll i=0;i<m;i++)
	std::cin>>b[i];
	for(ll i=0;i<m;i++)
	{
		ll j = bs(b[i]);
		std::cout<<j<<" "<<b[i]-arr[j-1]<<"\n";
	}	
	return 0;
}