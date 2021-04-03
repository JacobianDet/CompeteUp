#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

std::vector<ll> G[300001];
std::vector<ll> par(300001);
std::vector<ll> sx(300001, 1);

ll dfs_visit(ll s, ll p)
{
	par[s] = p;
	for(ll i=0,j=G[s].size();i<j;i++)
	{
		if(G[s][i] != p)
		sx[s] += dfs_visit(G[s][i], s);	
	}	
	return sx[s];	
}

int main(void)
{
	ll n,x,y;
	std::cin>>n>>x>>y;
	for(ll i=0;i<n-1;i++)
	{
		ll u,v;
		std::cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}	
	sx[x] += dfs_visit(x, 0);
	ll t = y;
	while(par[t] != x)
	t = par[t];
	std::cout<<n*(n-1) - (n - sx[t])*sx[y]<<"\n";
	return 0;		
}