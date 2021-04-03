#include <bits/stdc++.h>

int main(void)
{
	int n,v;
	std::cin>>n>>v;
	if(n-1 <= v)
	std::cout<<n-1<<"\n";
	else std::cout<<(v - 1 + (((n-v) * (n-v+1))>>1))<<"\n";
	return 0;	
}