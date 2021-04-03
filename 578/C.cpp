#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll n,m,q;
	std::cin>>n>>m>>q;
	ll gx = std::__gcd(n,m);
	ll ax = n/gx;
	ll bx = m/gx;
	while(q--)
	{
		ll sx, sy, ex, ey;
		std::cin>>sx>>sy>>ex>>ey;
		if(gx == 1)
		std::cout<<"YES\n";
		else
		{
			if(sx == 2 && ex == 1)
			{
				std::swap(sx, ex);
				std::swap(sy, ey);
				ll at = (sy + ax - 1)/ax;
				ll bt = (ey + bx - 1)/bx;
				if(at == bt)
				std::cout<<"YES\n";
				else std::cout<<"NO\n";
			}
			else if(sx == 1 && ex == 2)
			{
				ll at = (sy + ax - 1)/ax;
				ll bt = (ey + bx - 1)/bx;
				if(at == bt)
				std::cout<<"YES\n";
				else std::cout<<"NO\n";
			}		
			else if(sx == 1 && ex == 1)
			{
				ll at = (sy + ax - 1)/ax;
				ll bt = (ey + ax - 1)/ax;
				if(at == bt)
				std::cout<<"YES\n";
				else std::cout<<"NO\n";
			}	
			else
			{
				ll at = (sy + bx - 1)/bx;
				ll bt = (ey + bx - 1)/bx;
				if(at == bt)
				std::cout<<"YES\n";
				else std::cout<<"NO\n";
			}
		}	
	}	
	return 0;
}	