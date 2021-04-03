#include <bits/stdc++.h>

typedef long long ll;

ll bs2(ll n)
{
	ll lo = 1;
	ll hi = 1000000;
	while(lo < hi)
	{
		ll mid = lo + (hi - lo + 1)/2;
		if(mid * mid * mid <= n)
		lo = mid;
		else hi = mid - 1;	
	}
	if((lo * lo * lo) == n)
	return lo;
	else return -1;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	while(n--)
	{
		ll a,b;
		std::cin>>a>>b;
		ll z = a*b;
		ll k = bs2(z);
		if((k != -1) && !(a % k) && !(b % k)) 
		std::cout<<"YES\n";
		else std::cout<<"NO\n";	
	}
	return 0;
}