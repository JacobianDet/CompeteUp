#include <bits/stdc++.h>

int main(void)
{
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n;
		std::cin>>n;
		int arr[n+1];
		for(int i=0;i<n+1;i++)
		std::cin>>arr[i];
		std::cout<<"Case #"<<t<<": ";
		if(n & 1)
		std::cout<<"1\n0.000000000\n";	
		else std::cout<<"0\n";
	}	
	return 0;
}