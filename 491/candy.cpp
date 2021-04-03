#include <bits/stdc++.h>

typedef long long ll;

ll bs1(ll n)
{
	ll p = n/2;
	if(n & 1)
	p++;	
	ll lo = 1;
	ll hi = n;
	while(lo < hi)
	{
		ll mid = lo + (hi - lo)/2;
		ll r = n;
		ll x = 0;
		while(r)
		{
			if(r < mid)
			{
				x += r;
				r = 0;
			}	
			else
			{
				x += mid;
				r -= mid;
			}	
			r -= (r/10);
		}
		if(x >= p)
		hi = mid;
		else lo = mid + 1;	
	}
	return lo;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll n;
	std::cin>>n;
	ll canx = bs1(n);
	std::cout<<canx<<"\n";
	return 0;
}