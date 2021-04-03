#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		ll k;
		int x;
		std::cin>>k>>x;
		ll ax = x + (k-1)*9;
		std::cout<<ax<<"\n";
	}
	return 0;
}	
