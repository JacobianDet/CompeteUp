#include <bits/stdc++.h>

typedef long long ll;

int fun(ll n, ll k, int& fc)
{
	if(n <= 2)
	return k;
	if(k <= (1LL<<(n-2)))
	return fun(n-1, k, fc);
	else 
	{
		if(!(n & 1))
		{
			fc = (fc ^ 1);
			return fun(n-1, ((1LL<<(n-1)) - k + 1), fc);
		}	
		else return fun(n-1, ((1LL<<(n-1)) - k + 1), fc);
	}	
}

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		ll n,k;
		std::cin>>n>>k;
		int ans = 0;
		int fc = 0;
		if(n <= 60)
		ans = fun(n, k, fc);
		else ans = fun(60, k, fc);
		if(fc)
		{
			if(!(ans % 2))
			std::cout<<"Male\n";
			else std::cout<<"Female\n";	
		}	
		else
		{
			if(!(ans % 2))
			std::cout<<"Female\n";
			else std::cout<<"Male\n";	
		}	
	}	
	return 0;
}