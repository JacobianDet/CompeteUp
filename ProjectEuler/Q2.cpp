#include <bits/stdc++.h>
#define ll long long

int main(void)
{
	ll a = 2;
	ll b = 8;
	ll sum = a;
	while(b < 4000000)
	{
		ll temp = b;
		b = 4*b + a;
		a = temp;
		sum += a;
	}	
	std::cout<<sum<<"\n";
	return 0;
}