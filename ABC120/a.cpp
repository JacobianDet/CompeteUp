#include <bits/stdc++.h>

int main(void)
{
	int a,b,c;
	std::cin>>a>>b>>c;
	if(b >= a*c)
	std::cout<<c<<"\n";
	else std::cout<<(b/a)<<"\n";
	return 0;	
}