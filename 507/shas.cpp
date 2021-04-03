#include <bits/stdc++.h>

int main(void)
{
	int n,k;
	std::cin>>n>>k;
	if(n <= 2*k+1)
	{	
		std::cout<<"1\n";
		std::cout<<((n+1)>>1)<<"\n";
	}	
	else
	{
		int pos = -1;
		int minx = 100000000;
		for(int i=1;i<=k+1;i++)
		{
			if(((n-i+2*k+1) % (2*k+1)) <= k)
			{	
				int pmx = minx;
				minx = std::min(minx, (n-i+2*k+1)/(2*k+1));
				if((pmx > minx) && ((i + (minx-1)*(2*k+1)) <= n) && ((n - (i + (minx-1)*(2*k+1))) <= k))
				pos = i;
				else minx = pmx;
			}	
		}
		std::cout<<minx<<"\n";
		for(int i=0;i<minx;i++)
		{
			std::cout<<pos<<" ";
			pos += (2*k+1);
		}
		std::cout<<"\n";	
	}	
	return 0;
}