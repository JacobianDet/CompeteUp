#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

ll s[3000], cost[3000];
std::vector<ll> cp[3000];

bool cmp(ll a, ll b)
{
	return (cost[a] < cost[b]);
}

int main(void)
{
	ll n;
	std::cin>>n;
	for(ll i=0;i<n;i++)
	std::cin>>s[i];
	for(ll i=0;i<n;i++)
	std::cin>>cost[i];
	for(ll i=0;i<n;i++)
	{
		for(ll j=i+1;j<n;j++)
		{
			if(s[j] > s[i])
			cp[i].pb(j);	
		}
	}
	for(ll i=0;i<n;i++)
	std::sort(cp[i].begin(), cp[i].end(), cmp);
	std::vector<ll> act;
	for(ll i=0;i<n;i++)
	act.pb(i);
	std::sort(act.begin(), act.end(), cmp);
	ll mct = 1000000000;
	for(ll i=0;i<n;i++)
	{
		if(!cp[act[i]].empty())
		{
			ll ict1 = 1000000000;
			for(ll u=0,v=(ll)cp[act[i]].size();u<v;u++)
			{
				ll x = cp[act[i]][u];
				ll ict2 = 1000000000;
				if(!cp[x].empty())
				{	
					ict2 = cost[x] + cost[cp[x][0]];
					ict1 = std::min(ict1, ict2);
				}		
			}
			mct = std::min(mct, cost[act[i]] + ict1);	
		}
	}
	if(mct == 1000000000)
	std::cout<<"-1\n";
	else std::cout<<mct<<"\n";
	return 0;	
}