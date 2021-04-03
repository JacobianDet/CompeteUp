#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	ll n,w;
	std::cin>>n>>w;
	ll arr[n+1];
	memset(arr,0,sizeof(arr));
	for(ll i=1;i<=n;i++)
	{	
		std::cin>>arr[i];
		arr[i] += arr[i-1];
	}	
	ll lv=0, hv = w;
	for(int i=1;i<=n;i++)
	{
		lv = std::max(lv, -arr[i]);
		hv = std::min(hv, w-arr[i]);
	}	
	if(lv <= hv)
	std::cout<<hv-lv+1<<"\n";
	else std::cout<<"0\n";
	return 0;
}