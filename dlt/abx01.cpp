#include <bits/stdc++.h>
#define ll long long

ll bexp(ll x, ll n)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)
		res *= x;
		x *= x;
		n >>= 1;	
	}	
	return res;
}

ll digs(ll x)
{
	ll sum = 0;
	while(sum >= 10 || !sum)
	{
		sum = 0;
		while(x)
		{
			sum += x%10;
			x /= 10;
		}	
		x = sum;
	}	
	return x;
}

int main(void)
{
	int T;
	std::cin>>T;
	for(int i=0;i<T;i++)
	{
		ll a,n;
		std::cin>>a>>n;
		ll z = bexp(a,n);
		ll ds = digs(z);
		std::cout<<ds<<"\n";
	}	
	return 0;
}