#include <bits/stdc++.h>
#define mp std::make_pair

typedef long long ll;

std::map<ll, ll> sxt;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	{
		ll v,t;
		std::cin>>v>>t;
		sxt[v]++;
		sxt[v+t]--;
	}
	auto pit = sxt.begin();
	for(auto it = sxt.begin();it != sxt.end();it++)
	{
		if(it != pit)
		{
			it->second += pit->second;
			pit = it;
		}		
	}	
	ll ans = 1;
	for(auto u : sxt)	
	ans = std::max(ans, u.second);
	std::cout<<ans<<"\n";
	return 0;	
}