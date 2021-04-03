#include <bits/stdc++.h>
#define ll long long

int main(void)
{
	ll l,r;
	std::cin>>l>>r;
	ll z = ((~l) & r);
	if(z == 0)
	std::cout<<z<<"\n";
	else
	{	
		while(z & (z-1))
		z &= (z-1);
		std::cout<<(z ^ (z-1))<<"\n";
	}	
	return 0;	
}