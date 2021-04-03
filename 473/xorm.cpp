#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	ll n;
	std::cin>>n;
	ll msts = 0;
	for(ll i=0;(1LL<<i)<n;i++)
	msts += (((n-1-(1LL<<i))/(1LL<<(i+1)))+1)*(1LL<<i);
	std::cout<<msts<<"\n";
	return 0;
}