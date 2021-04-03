#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	ll n;
	int q;
	std::cin>>n>>q;
	while(q--)
	{
		ll v;
		std::cin>>v;
		if(v & 1)
		std::cout<<((v + 1)>>1)<<"\n";
		else
		{
			ll z = 0, x = 0;
			while(x < 61)
			{	
				if(!((v + (1LL<<(x+1)) - (n<<1)) % (1LL<<(x+2))))
				{ 
					z = (v + (1LL<<(x+1)) - (n<<1))/(1LL<<(x+2)) + n;
					break;
				}
				x++;
			}			
			std::cout<<z<<"\n";
		}	
	}
	return 0;	
}