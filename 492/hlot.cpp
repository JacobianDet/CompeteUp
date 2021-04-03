#include <bits/stdc++.h>

int main(void)
{
	int n;
	std::cin>>n;
	int cx[5] = {100, 20, 10, 5, 1};
	int i = 0;
	int ct = 0;
	while(n)
	{
		ct += (n/cx[i]);
		n -= (n/cx[i])*cx[i];
		i++;
	}	
	std::cout<<ct<<"\n";
	return 0;
}