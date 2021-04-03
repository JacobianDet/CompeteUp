#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	while(T--)
	{
		ll s,a,b,c;
		std::cin>>s>>a>>b>>c;
		std::cout<<((s/c) + ((s/c)/a)*b)<<"\n";
	}
	return 0;
}