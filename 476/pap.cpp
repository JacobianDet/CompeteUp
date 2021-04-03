#include <bits/stdc++.h>

int main(void)
{
	int k,n,s,p;
	std::cin>>k>>n>>s>>p;
	int nos = k * ceil((float)n/s);
	int nop = ceil((float)nos/p);
	std::cout<<nop<<"\n";
	return 0;
}