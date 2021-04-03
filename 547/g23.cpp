#include <bits/stdc++.h>

int main(void)
{
	int n,m;
	std::cin>>n>>m;
	if(m % n)
	std::cout<<"-1\n";
	else
	{
		int ax = m/n;
		int c2 = 0, c3 = 0;
		while(!(ax % 2))
		{
			ax /= 2;
			c2++;
		}
		while(!(ax % 3))
		{
			ax /= 3;
			c3++;
		}
		if(ax > 1)
		std::cout<<"-1\n";
		else std::cout<<(c2 + c3)<<"\n";	
	}	
	return 0;
}