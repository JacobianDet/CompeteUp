#include <bits/stdc++.h>

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int ang;
		std::cin>>ang;
		if(!(360 % (180 - ang)))
		std::cout<<360/(180 - ang)<<"\n";
		else
		{
			int cang = (ang<<1);
			if(cang > 180)
			cang = 360 - cang;	
			std::cout<<360/std::__gcd(360, cang)<<"\n";
		}
	}
	return 0;
}