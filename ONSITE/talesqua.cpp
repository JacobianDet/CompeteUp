#include <bits/stdc++.h>
#define mp std::make_pair

typedef long long ll;
typedef long double ld;

int main(void)
{
	ll T;
	std::cin>>T;
	while(T--)
	{
		ll a,k;
		std::cin>>a>>k;
		ll x[3];
		for(ll i=0;i<3;i++)
		std::cin>>x[i];
		std::sort(x, x+3);
		std::pair<ld, ld> arr[3];
		for(ll i=0;i<3;i++)
		arr[i] = mp((ld)x[i] - (ld)a/2 - (ld)k, (ld)x[i] + (ld)a/2 + (ld)k);		
		ld l = -10000001, r = 10000001;
		for(ll i=0;i<3;i++)
		{
			l = std::max(l, arr[i].first);
			r = std::min(r, arr[i].second);
		}	
		if(l > r)
		std::cout<<"0.0000\n";
		else printf("%.5Lf\n", std::min((r - l)*a, (ld)a*a));	
	}	
	return 0;
}