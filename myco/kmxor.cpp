#include <bits/stdc++.h>

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n,k;
		std::cin>>n>>k;
		int z = k;
		while(z & (z-1))
		z &= (z-1);
		int ctr = __builtin_ctz(z) + 1;
		if(k == 1)
		{
			for(int i=0;i<n;i++)
			std::cout<<k<<" ";
			std::cout<<"\n";	
		}	
		else if(k == 2)
		{
			if(n & 1)
			{
				for(int i=0;i<n;i++)
				std::cout<<k<<" ";
				std::cout<<"\n";	
			}	
			else
			{
				std::cout<<"1 ";
				for(int i=1;i<n;i++)
				std::cout<<k<<" ";
				std::cout<<"\n";	
			}	
		}
		else if(k == 3)
		{
			if(n & 1)
			{
				for(int i=0;i<n;i++)
				std::cout<<k<<" ";
				std::cout<<"\n";	
			}	
			else
			{
				for(int i=0;i<ctr;i++)
				{
					std::cout<<z<<" ";
					z >>= 1;
				}	
				for(int i=0;i<(n-ctr);i++)
				std::cout<<k<<" ";
				std::cout<<"\n";
			}	
		}
		else
		{
			if(n < ctr)
			{
				if(n == 1)
				std::cout<<k<<"\n";
				else
				{
					for(int i=0;i<n-1;i++)
					{
						std::cout<<z<<" ";
						z >>= 1;
					}
					z ^= (z-1);
					std::cout<<z<<"\n";	
				}	
			}	
			else
			{
				if((n-ctr) & 1)
				{
					for(int i=0;i<ctr-2;i++)
					{
						std::cout<<z<<" ";
						z >>= 1;
					}	
					z ^= (z-1);
					std::cout<<z<<" ";
					for(int i=0;i<(n-ctr+1);i++)
					std::cout<<k<<" ";
					std::cout<<"\n";	
				}	
				else
				{
					for(int i=0;i<ctr;i++)
					{
						std::cout<<z<<" ";
						z >>= 1;
					}	
					for(int i=0;i<(n-ctr);i++)
					std::cout<<k<<" ";
					std::cout<<"\n";
				}	
			}	
		}	
	}
	return 0;	
}