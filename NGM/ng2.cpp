#include <bits/stdc++.h>

typedef long long ll;

ll arr[20];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll n;
	int k;
	std::cin>>n>>k;
	for(int i=0;i<k;i++)
	std::cin>>arr[i];
	ll ans = 0;
	for(ll i=0;i<(1<<k);i++)
	{
		ll z = n;
		ll lc = 1;
		for(ll j=0;j<k;j++)
		{
			if((i & (1<<j)))
			lc = arr[j] * lc/std::__gcd(lc, arr[j]);
		}	
		if(__builtin_popcountll(i) & 1)
		ans -= (z/lc);
		else ans += (z/lc);	
	}	
	std::cout<<ans<<"\n";
	return 0;
}