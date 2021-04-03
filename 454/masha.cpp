#include <bits/stdc++.h>

int main(void)
{
	int v1,v2,v3,vm;
	std::cin>>v1>>v2>>v3>>vm;
	if((vm < v2 && vm >= v3) && (2*v3 >= vm))
	std::cout<<2*v1<<"\n"<<2*v2<<"\n"<<2*v3<<"\n";
	else if((vm < v3) && (2*vm >= v3))
	std::cout<<2*v1<<"\n"<<2*v2<<"\n"<<v3<<"\n";
	else std::cout<<"-1\n";
	return 0;	
}