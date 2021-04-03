#include <bits/stdc++.h>
#define CHOR 100000
#define MOD 1000000007
typedef long long ll;

std::string s;
ll memo[CHOR];
ll dx[CHOR];

ll dsub(ll i)
{
	if(i == s.size())
	return 1;
	if(memo[i] != -1)
	return memo[i];
	ll ans = 0;
	ll x = dsub(i+1)%MOD;
	ll y = 0;
	if(s.find(s[i], i+1) != std::string::npos)
	y = dsub(s.find(s[i], i+1)+1)%MOD;	
	ans = (2*x - y + MOD)%MOD;
	memo[i] = ans;
	return ans;
}

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		memset(memo, -1, sizeof(memo));
		std::cin>>s;
		ll ans = dsub(0);
		std::cout<<ans<<"\n";	
	}	
	return 0;
}