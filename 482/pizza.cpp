#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	ll n;
	std::cin>>n;
	if(n && ((n+1) & 1))
	std::cout<<n+1<<"\n";
	else std::cout<<((n+1) >> 1LL)<<"\n";	
	return 0;	
}