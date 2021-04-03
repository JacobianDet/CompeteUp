#include <bits/stdc++.h>

typedef long long ll;

ll anton(ll n, ll m)
{
	if(n <= m)
	return n;
	ll lo = 1;
	ll hi = 2000000000;
	while(lo < hi)
	{
		ll mid = lo + (hi-lo)/2;
		ll res_no = n - m - mid*(mid+1)/2;
		if(res_no <= 0)
		hi = mid;
		else lo = mid + 1;
	}	
	return lo + m;
}

int main(void)
{
	ll n, m;
	std::cin>>n>>m;
	ll ans = anton(n, m);
	std::cout<<ans<<"\n";
	return 0;
}