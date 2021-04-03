#include <bits/stdc++.h>

typedef long long ll;

ll cst[61];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	while(T--)
	{	
		ll n,L;
		std::cin>>n>>L;
		for(ll i=0;i<n;i++)
		std::cin>>cst[i];
		for(ll i=1;i<n;i++)
		cst[i] = std::min(cst[i], 2*cst[i-1]);
		ll ans = 1000000000000000000, sx = 0;
		for(ll i=n-1;i>=0;i--)
		{
			ll req = L/(1LL<<i);
			sx += req * cst[i];
			L -= req<<i;
			ans = std::min(ans, sx + (L > 0) * cst[i]);
		}	
		std::cout<<ans<<"\n";
	}	
	return 0;
}