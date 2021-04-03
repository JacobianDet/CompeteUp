#include <bits/stdc++.h>

bool pfind(int n)
{
	for(int i=2;i*i<=n;i++)
	{
		if(!(n % i))
		return 0;	
	}	
	return 1;
}

int main(void)
{
	int n;
	std::cin>>n;
	if(pfind(n))
	std::cout<<"1\n";
	else
	{
		if(!(n & 1))
		std::cout<<"2\n";
		else if((n & 1) && pfind(n - 2))
		std::cout<<"2\n";
		else std::cout<<"3\n";	
	}	
	return 0;
}