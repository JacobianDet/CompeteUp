#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

typedef long long ll;

std::vector<int> G[100001];
ll mdx[100001], gx[100001];

bool dfs_vis1(int s, int p)
{
	bool ax = 1;
	if(p != -1)
	{	
		if((gx[s] != -1) && (gx[s] < mdx[p]))
		ax = 0;
		mdx[s] = std::max(mdx[p], gx[s]);
	}
	if(gx[s] >= 0)
	mdx[s] = std::max(mdx[s], gx[s]);		
	for(auto u : G[s])
	{
		if(u != p)
		ax &= dfs_vis1(u, s);	
	}
	return ax;
}

std::pair<ll, ll> dfs_vis2(int s, int p)
{
	std::vector<ll> abd;
	ll ans1 = 0, ans2 = -1;
	if(gx[s] != -1)
	{
		for(auto u : G[s])
		{
			if(u != p)
			{
				std::pair<ll, ll> px = dfs_vis2(u, s);
				ans1 += px.first;
				if(px.second != -1)
				ans1 += (px.second - gx[s]);	
			}
		}
		ans2 = gx[s];
	}
	else
	{
		for(auto u : G[s])
		{
			if(u != p)
			{
				std::pair<ll, ll> px = dfs_vis2(u, s);
				ans1 += px.first;
				if(px.second != -1)
				{	
					abd.pb(px.second);
					if(ans2 == -1)
					ans2 = px.second;
					else ans2 = std::min(ans2, px.second);
				}	
			}
		}
		if(ans2 != -1)
		{	
			for(auto u : abd)
			ans1 += (u - ans2);	
		}	
	}
	return mp(ans1, ans2);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=2;i<=n;i++)
	{
		int p;
		std::cin>>p;
		G[i].pb(p);
		G[p].pb(i);
	}
	for(int i=1;i<=n;i++)
	std::cin>>gx[i];	
	bool xd = dfs_vis1(1, -1);
	if(!xd)
	std::cout<<"-1\n";
	else
	{
		std::pair<ll, ll> px = dfs_vis2(1, -1);
		ll ans = px.first + ((px.second != -1) ? px.second : 0);
		std::cout<<ans<<"\n";
	}	
	return 0;
}