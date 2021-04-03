#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	ll a,b,x,y;
	std::cin>>a>>b>>x>>y;
	ll gcx = std::__gcd(x, y);
	x /= gcx;
	y /= gcx;
	ll ans = std::min(a/x, b/y);
	std::cout<<ans<<"\n";
	return 0;
}