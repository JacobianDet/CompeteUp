#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

int main(void)
{
	ll x,y;
	std::cin>>x>>y;
	if(x == y)
	std::cout<<"=\n";
	else
	{
		ld lx = log((ld)x)/log(2);
		ld ly = log((ld)y)/log(2);
		ld X = y*lx;
		ld Y = x*ly;
		if(X > Y)
		std::cout<<">\n";
		else if(X < Y) 
		std::cout<<"<\n";
		else std::cout<<"=\n";	
	}	
	return 0;
}