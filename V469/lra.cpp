#include <bits/stdc++.h>

int main(void)
{
	int l,r,a;
	std::cin>>l>>r>>a;
	if(l >= r)
	{
		if(l >= r + a)
		std::cout<<((r + a)<<1)<<"\n";
		else
		{
			int diff = l - r;
			std::cout<<((l + ((a - diff)>>1))<<1)<<"\n";
		}	
	}
	else
	{
		if(r >= l + a)
		std::cout<<((l + a)<<1)<<"\n";
		else
		{
			int diff = r - l;
			std::cout<<((r + ((a - diff)>>1))<<1)<<"\n";
		}	
	}	
	return 0;
}