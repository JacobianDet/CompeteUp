#include <bits/stdc++.h>

int main(void)
{
	int n;
	std::cin>>n;
	if(!(n % 10))
	std::cout<<"2\n";
	else std::cout<<"1\n"<<(n % 10)<<"\n";
	return 0;
}