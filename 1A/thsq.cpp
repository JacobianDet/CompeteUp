#include <bits/stdc++.h>

typedef long long int ll;

int main(void)
{
	ll n,m,a;
	std::cin>>n>>m>>a;
	std::cout<<(ll)ceil((double)n/a)*(ll)ceil((double)m/a)<<"\n";
	return 0;
}