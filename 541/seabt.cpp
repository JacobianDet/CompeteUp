#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	ll w1, h1, w2, h2;
	std::cin>>w1>>h1>>w2>>h2;
	ll ans = ((w1 + 2) * (h1 + 2)) + ((w2 + 2) * h2) - (w1 * h1) - (w2 * h2);
	std::cout<<ans<<"\n";
	return 0;
}