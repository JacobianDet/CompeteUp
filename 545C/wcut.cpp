#include <bits/stdc++.h>
#define ll long long
#define mp std::make_pair
#define pb push_back

std::vector<std::pair<ll, ll> > G;
ll n;
ll memo[100000][3];

ll wcut(ll i, int ch)
{
	if(i == n-1)
	return 1;
	if(memo[i][ch] != -1)
	return memo[i][ch];	
	ll ans = 0;
	if(i == 0)
	ans = 1 + wcut(i+1, 1);
	else
	{	
		ll llim = G[i].first - G[i].second;
		ll rlim = G[i].first + G[i].second;
		ll prlim = G[i-1].first + G[i-1].second;
		if((ch == 2 && llim > prlim) || (ch != 2 && llim > G[i-1].first)) 
		ans = std::max(ans, 1 + wcut(i+1, 1));
		if(rlim < G[i+1].first)
		ans = std::max(ans, 1 + wcut(i+1, 2));
		ans = std::max(ans, wcut(i+1, 0));
	}
	memo[i][ch] = ans;
	return ans;	
}

int main(void)
{
	memset(memo,-1,sizeof(memo));
	std::cin>>n;
	for(ll i=0;i<n;i++)
	{
		ll x,h;
		std::cin>>x>>h;
		G.pb(mp(x, h));
	}	
	ll ans = wcut(0, 0);
	std::cout<<ans<<"\n";
	return 0;
}