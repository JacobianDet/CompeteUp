#include <bits/stdc++.h>

int main(void)
{
	int n,m;
	std::cin>>n>>m;
	if(m == n)
	{
		for(int i=0;i<n;i++)
		std::cout<<"10";
		std::cout<<"\n";	
	}	
	else if(n == m + 1)
	{
		std::cout<<"0";
		for(int i=0;i<m;i++)
		std::cout<<"10";
		std::cout<<"\n";	
	}
	else if(m == 2*(n + 1))
	{
		std::cout<<"11";
		for(int i=0;i<n;i++)
		std::cout<<"011";
		std::cout<<"\n";	
	}	
	else if(m == n + 1)
	{
		std::cout<<"1";
		for(int i=0;i<n;i++)
		std::cout<<"01";
		std::cout<<"\n";	
	}	
	else if(m > (n + 1) && m < 2*(n + 1))
	{
		int d = m%(n+1);
		std::cout<<"11";
		for(int i=0;i<d-1;i++)
		std::cout<<"011";
		for(int i=0;i<n-d+1;i++)
		std::cout<<"01";	
		std::cout<<"\n";
	}	
	else std::cout<<"-1\n";
	return 0;
}