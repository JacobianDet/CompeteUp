#include <bits/stdc++.h>

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int x;
		std::cin>>x;
		if(!(x % 5) && !(x % 2))
		std::cout<<"0\n";
		else if(!(x % 5))
		std::cout<<"1\n";
		else std::cout<<"-1\n";	
	}	
	return 0;
}