#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		ll n;
		std::cin>>n;
		ll arr[n];
		for(ll i=0;i<n;i++)
		std::cin>>arr[i];
		ll xora = 0;
		for(ll i=0;i<n;i++)
		xora ^= (arr[i] << 1);
		std::cout<<xora<<"\n";
	}	
	return 0;
}