#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		ll k,p,n;
		std::cin>>k>>p>>n;
		if(k <= p)
		std::cout<<"0\n";
		else std::cout<<((k - p)*n)<<"\n";	
	}
	return 0;
}