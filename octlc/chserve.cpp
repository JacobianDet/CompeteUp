#include <bits/stdc++.h>

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int p1,p2,k;
		std::cin>>p1>>p2>>k;
		if(!(((p1 + p2)/k) % 2))
		std::cout<<"CHEF\n";
		else std::cout<<"COOK\n";	
	}
	return 0;
}