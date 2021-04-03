#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	ll n,k;
	std::cin>>n>>k;
	if(k % n)
	std::cout<<(k/n) + 1<<"\n";
	else std::cout<<(k/n)<<"\n";
	return 0;
}