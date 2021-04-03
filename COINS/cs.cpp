#include <bits/stdc++.h>

typedef long long ll;

std::map<ll, ll> memo;

ll coinex(ll n)
{
	if(n <= 3)
	return n;
	if(memo.find(n) != memo.end())
	return memo[n];	
	ll ans = 0;
	ans = std::max(n, (coinex(n/2) + coinex(n/3) + coinex(n/4)));	
	memo[n] = ans;
	return ans;
}

int main(void)
{
	ll n;
	while(std::cin>>n)
	{
		ll ans = coinex(n);
		std::cout<<ans<<"\n";
		memo.clear();
	}	
	return 0;
}
