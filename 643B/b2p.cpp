#include <bits/stdc++.h>

int main(void)
{
	int n,k,a,b,c,d;
	std::cin>>n>>k>>a>>b>>c>>d;
	if(n<=4 || k<=n)
	std::cout<<"-1\n";
	else
	{
		std::cout<<a<<" "<<c<<" ";
		for(int i=1;i<=n;i++)
		{
			if((i != a) && (i != b) && (i != c) && (i != d))
			std::cout<<i<<" ";
		}
		std::cout<<d<<" "<<b<<"\n";
		std::cout<<c<<" "<<a<<" ";
		for(int i=1;i<=n;i++)
		{
			if((i != a) && (i != b) && (i != c) && (i != d))
			std::cout<<i<<" ";
		}
		std::cout<<b<<" "<<d<<"\n";
	}
	return 0;
}	
