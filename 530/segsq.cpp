#include <bits/stdc++.h>

typedef long long ll;

ll bs2(ll val)
{
	ll lo = 1;
	ll hi = 100001;
	while(lo < hi)
	{
		ll mid = lo + (hi - lo + 1)/2;
		if(mid * mid <= val)
		lo = mid;
		else hi = mid - 1;	
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
	ll xd = bs2(n);
	if(xd * xd == n)
	std::cout<<(xd<<1)<<"\n";
	else if(((xd * xd) + 1) <= n && ((xd * xd) + (xd + 1)) > n)
	std::cout<<((xd<<1) + 1)<<"\n";
	else std::cout<<((xd + 1)<<1)<<"\n";
	return 0; 	
}