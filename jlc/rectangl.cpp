#include <bits/stdc++.h>

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int a,b,c,d;
		std::cin>>a>>b>>c>>d;
		if(((a == b) && (c == d)) || ((a == c) && (b == d)) || ((a == d) && (b == c)))
		std::cout<<"YES\n";
		else std::cout<<"NO\n";	
	}	
	return 0;
}