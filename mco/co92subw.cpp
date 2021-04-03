#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		ll x;
		std::cin>>x;	
		ld z = (sqrt(8*x + 1) - 1)/2;
		ll a = ceil(z);
		ll b = floor(z);
		//std::cout<<z<<" "<<a<<" "<<b<<"\n";
		ll ans = std::min(a + fabs((ll)a*(a+1)/2 - x), b + fabs((ll)b*(b+1)/2 - x));
		std::cout<<ans<<"\n";
	}	
	return 0;
}