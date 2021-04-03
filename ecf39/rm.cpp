#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	ll a,b;
	std::cin>>a>>b;
	while(a && b)
	{
		if(a - 2*b >= 0)
		a %= 2*b;
		else if(b - 2*a >= 0)
		b %= 2*a;
		else break;	
	}	
	std::cout<<a<<" "<<b<<"\n";
	return 0;
}