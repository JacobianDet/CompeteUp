#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	int q;
	std::cin>>q;
	while(q--)
	{
		ll n,m,k;
		std::cin>>n>>m>>k;
		ll mnx = 0;
		ll diff = 0;
		if(n > m)
		{	
			mnx = m;
			diff = n - m;
		}	
		else 
		{
			mnx = n;
			diff = m - n;
		}	
		if(mnx + diff > k)
		std::cout<<"-1\n";
		else
		{
			if(diff & 1)
			std::cout<<k-1<<"\n";
			else
			{
				if((k - mnx - diff) & 1)
				std::cout<<k-2<<"\n";
				else std::cout<<k<<"\n";
			}
		}	
	}
	return 0;
}