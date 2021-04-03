#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int q;
	std::cin>>q;
	while(q--)
	{
		ll n,a,b;
		std::cin>>n>>a>>b;
		if(((a<<1) - b) >= 0)
		std::cout<<(a*n - (n>>1) * ((a<<1) - b))<<"\n";
		else std::cout<<a*n<<"\n";	
	}
	return 0;
}