#include <bits/stdc++.h>

int main(void)
{
	int a,b,c,n;
	std::cin>>a>>b>>c>>n;
	int z = n - (a + b - c);
	if((z < 1) || (a > n) || (b > n) || (c > n) || (z > n) || (c > a) || (c > b))
	std::cout<<"-1\n";
	else std::cout<<z<<"\n";
	return 0;	
}