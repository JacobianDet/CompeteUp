#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	ll n,k;
	std::cin>>n>>k;
	if(n >= k-1)
	{
		if(k & 1)
		std::cout<<(k>>1)<<"\n";
		else std::cout<<((k>>1) - 1)<<"\n";	
	}
	else if(n < ((k>>1) + 1))
	std::cout<<"0\n";
	else std::cout<<(n - (k>>1))<<"\n";
	return 0;
}