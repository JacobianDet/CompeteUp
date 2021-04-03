#include <bits/stdc++.h>
#define ull unsigned long long

int main(void)
{
	ull n,k;
	std::cin>>n>>k;
	if(k == 1)
	std::cout<<n<<"\n";
	else
	{
		ull z = n;
		while(z & (z-1))
		z &= (z-1);
		std::cout<<(z ^ (z-1))<<"\n";	
	}	
	return 0;
}