#include <bits/stdc++.h>

int main(void)
{
	int n,m;
	std::cin>>n>>m;
	if(n < m)
	{
		std::cout<<n+1<<"\n";
		for(int i=0;i<=n;i++)
		std::cout<<i<<" "<<i+1<<"\n";	
	}	
	else if(n > m)
	{
		std::cout<<m+1<<"\n";
		for(int i=0;i<=m;i++)
		std::cout<<i+1<<" "<<i<<"\n";	
	}
	else
	{
		std::cout<<m+1<<"\n";
		for(int i=0;i<=m;i++)
		std::cout<<m-i<<" "<<i<<"\n";	
	}
	return 0;
}