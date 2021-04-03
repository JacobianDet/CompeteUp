#include <bits/stdc++.h>
#define mp std::make_pair

typedef long long ll;

ll W[100001];
ll n;
std::pair<ll, ll> memo[100001];

std::pair<ll, ll> stk(ll i)
{
	if(i == 1)
	return mp(W[1], 1);
	if(memo[i] != mp(-1*1LL, -1*1LL))
	return memo[i];
	std::pair<ll, ll> ans = mp(0, 0);
	for(ll j=i-1;j>=1;j--)
	{
		if(6*W[i] >= stk(j).first && ans.second <= stk(j).second)
		ans = mp(W[i] + stk(j).first, 1 + stk(j).second);	
	}	
	memo[i] = ans;
	return ans;
}

int main(void)
{
	int T;
	std::cin>>T;
	for(ll t=1;t<=T;t++)
	{
		memset(W,0,sizeof(W));
		for(ll i=0;i<100001;i++)
		memo[i] = mp(-1*1LL, -1*1LL);	
		std::cin>>n;
		for(ll i=1;i<=n;i++)
		std::cin>>W[i];
		ll ans = 0;
		for(ll i=n;i>=1;i--)
		ans = std::max(ans, stk(i).second);
		std::cout<<"Case #"<<t<<": "<<ans<<"\n";	
	}	
	return 0;
}