#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll n,a,b,p,q;
	std::cin>>n>>a>>b>>p>>q;
	ll lcx = (a*b)/std::__gcd(a, b);
	ll mc = std::min(p, q);
	std::cout<<(p*(n/a) + q*(n/b) - mc*(n/lcx))<<"\n";
	return 0;
}