#include <bits/stdc++.h>
#define ll long long

int main(void)
{
	ll n;
	std::cin>>n;
	ll temp = n;
	ll dig = 0;
	while(temp)
	{
		dig++;
		temp /= 10;
	}	
	for(ll i=0;i<dig;i++)
	{
		if(i < (dig >> 1))
		temp = 10*temp + 7;
		else temp = 10*temp + 4;	
	}
	if(dig & 1)
	{
		dig++;
		for(ll i=0;i<dig;i++)
		{
			if(i < (dig >> 1))
			std::cout<<"4";
			else std::cout<<"7";	
		}	
		std::cout<<"\n";
	}	
	else if(!(dig & 1) && (n > temp))
	{
		dig += 2;
		for(ll i=0;i<dig;i++)
		{
			if(i < (dig >> 1))
			std::cout<<"4";
			else std::cout<<"7";	
		}	
		std::cout<<"\n";
	}		
	else
	{
		for(ll i=0;i<(1 << dig);i++)
		{
			ll c4=0,c7=0,ans=0;
			for(ll j=(dig-1);j>=0;j--)
			{
				if(i & (1 << j))
				{	
					ans = 10*ans + 7;
					c7++;
				}	
				else 
				{
					ans = 10*ans + 4;
					c4++;	
				}	
			}	
			if((c4 == c7) && (ans >= n))
			{
				std::cout<<ans<<"\n";
				break;
			}	
		}	
	}
	return 0;	
}