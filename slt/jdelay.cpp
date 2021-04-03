#include <bits/stdc++.h>
#define mp std::make_pair

std::pair<int, int> arr[101];

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n;
		std::cin>>n;
		for(int i=0;i<n;i++)
		{
			int x,y;
			std::cin>>x>>y;
			arr[i] = mp(x, y);
		}	
		int ct = 0;
		for(int i=0;i<n;i++)
		{
			if((arr[i].second - arr[i].first) > 5)
			ct++;	
		}	
		std::cout<<ct<<"\n";
	}
	return 0;
}