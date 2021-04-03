#include <bits/stdc++.h>

int main(void)
{
	int n,h,w;
	std::cin>>n>>h>>w;
	int ct = 0;
	for(int i=0;i<n;i++)
	{
		int a,b;
		std::cin>>a>>b;
		if(a >= h && b >= w)
		ct++;	
	}
	std::cout<<ct<<"\n";
}