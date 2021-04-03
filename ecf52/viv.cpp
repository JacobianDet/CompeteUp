#include <bits/stdc++.h>

typedef long long ll;

ll bs1(ll n, ll m)
{
	ll lo = 1;
	ll hi = n;
	while(lo < hi)
	{
		ll mid = lo + (hi - lo)/2;
		if(((mid * (mid - 1)) >> 1) >= m)
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
	ll n,m;
	std::cin>>n>>m;
	if(!m)
	std::cout<<n<<" "<<n<<"\n";
	else 
	{
		ll ans = bs1(n, m);
		std::cout<<(((n - 2*m) >= 0) ? (n - 2*m) : 0)<<" "<<(n - ans)<<"\n";
	}	
	return 0;
}