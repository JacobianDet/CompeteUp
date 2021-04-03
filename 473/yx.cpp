#include <bits/stdc++.h>

int main(void)
{
	int n;
	std::cin>>n;
	if(n <= 5)
	{
		std::cout<<"-1\n";
		for(int i=1;i<n;i++)
		std::cout<<i<<" "<<i+1<<"\n";	
	}	
	else
	{
		for(int i=2;i<n-1;i++)
		std::cout<<"1 "<<i<<"\n";
		std::cout<<"2 "<<n-1<<"\n2 "<<n<<"\n";
		for(int i=1;i<n;i++)
		std::cout<<i<<" "<<i+1<<"\n";	
	}	
	return 0;
}