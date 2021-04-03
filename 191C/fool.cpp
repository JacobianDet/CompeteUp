#include <bits/stdc++.h>
#define CHOR 100001
#define pb push_back
#define mp std::make_pair

typedef long long ll;

std::vector<ll> G[CHOR];
std::pair<ll, ll> E[CHOR];
ll lvl[CHOR], par[CHOR], cx[CHOR], zno[CHOR];
ll P[CHOR][20];
ll tz;

void dfs_vis1(ll s, ll p)
{
	tz++;
	zno[s] = tz;
	if(p != -1)
	{
		lvl[s] = 1 + lvl[p];
		par[s] = p;
	}	
	for(ll i=0,j=(ll)G[s].size();i<j;i++)
	{
		if(G[s][i] != p)
		dfs_vis1(G[s][i], s);	
	}	
	return;
}

ll dfs_vis2(ll s, ll p)
{
	for(ll i=0,j=(ll)G[s].size();i<j;i++)
	{
		if(G[s][i] != p)
		cx[s] += dfs_vis2(G[s][i], s);	
	}	
	return cx[s];
}

void ST_build(ll n)
{
	for(ll i=1;i<=n;i++)
	{
		for(ll j=0;(1LL<<j)<=n;j++)
		P[i][j] = -1;	
	}	
	for(ll i=1;i<=n;i++)
	P[i][0] = par[i];
	for(ll j=1;(1LL<<j)<=n;j++)
	{
		for(ll i=1;i<=n;i++)
		{
			if(P[i][j-1] != -1)
			P[i][j] = P[P[i][j-1]][j-1];	
		}	
	}	
	return;
}

ll LCA_find(ll p, ll q)
{
	if(lvl[p] < lvl[q])
	{
		ll tmp = p;
		p = q;
		q = tmp;
	}	
	ll lx = 0;
	for(lx=1;(1LL<<lx)<=lvl[p];lx++);
	lx--;
	for(ll i=lx;i>=0;i--)
	{
		if((lvl[p] - (1LL<<i)) >= lvl[q])
		p = P[p][i];	
	}	
	if(p == q)
	return p;
	for(ll i=lx;i>=0;i--)
	{
		if((P[p][i] != -1) && (P[p][i] != P[q][i]))
		{
			p = P[p][i];
			q = P[q][i];
		}	
	}
	return par[p];	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll n;
	std::cin>>n;
	for(ll i=0;i<n-1;i++)
	{
		ll s,d;
		std::cin>>s>>d;
		E[i] = mp(s, d);
		G[s].pb(d);
		G[d].pb(s);
	}	
	tz = 0;
	dfs_vis1(1, -1);
	ST_build(n);
	ll q;
	std::cin>>q;
	while(q--)
	{
		ll s,d;
		std::cin>>s>>d;
		ll lca = LCA_find(s, d);
		cx[s] += 1;
		cx[d] += 1;
		cx[lca] -= 2;
	}	
	cx[1] = dfs_vis2(1, -1);
	for(ll i=0;i<n-1;i++)
	{
		ll s = E[i].first;
		ll d = E[i].second;
		if(zno[s] > zno[d])
		std::cout<<cx[s]<<" ";
		else std::cout<<cx[d]<<" ";	
	}	
	std::cout<<"\n";
	return 0;
}