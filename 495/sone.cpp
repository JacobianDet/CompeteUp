#include <bits/stdc++.h>
#define mp std::make_pair

//int sol[1001];

int main(void)
{
	int n,m;
	std::cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		std::cin>>x>>y;
	}	
	for(int i=0;i<n;i++)
	{
		if(i & 1)
		std::cout<<'1';
		else std::cout<<'0';	
	}
	std::cout<<"\n";
	return 0;
}