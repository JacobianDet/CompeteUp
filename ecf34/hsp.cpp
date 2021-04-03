#include <bits/stdc++.h>

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	{
		int a;
		std::cin>>a;
		if(floor((float)a/3) >= ceil((float)2*a/7))
		std::cout<<"YES\n";
		else std::cout<<"NO\n";	
	}	
	return 0;
}