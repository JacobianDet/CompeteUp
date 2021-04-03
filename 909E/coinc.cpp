#include <bits/stdc++.h>

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n;
		std::cin>>n;
		if(!(n % 6))
		std::cout<<"Misha\n";
		else std::cout<<"Chef\n";
	}
	return 0;
}	
