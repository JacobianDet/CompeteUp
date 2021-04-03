#include <bits/stdc++.h>
#define CHOR 200001
#define mp std::make_pair
#define pb push_back
#define INF 1000000000000

typedef long long ll;

std::vector<std::pair<ll, ll> > G[CHOR];
std::pair<std::pair<ll, ll>, ll> E[CHOR];
std::vector<std::pair<ll, ll> > T[CHOR];
ll par[CHOR], dist[CHOR], lvl[CHOR];
ll P[CHOR][20], mdst[CHOR][20];
bool isMST[CHOR];

ll PrimMST(ll n)
{
	for(ll i=1;i<=n;i++)
	{
		dist[i] = INF;
		isMST[i] = 0;
	}	
	std::set<std::pair<ll, ll> > S;
	S.insert(mp(0, 1));
	dist[1] = 0;
	ll tot = 0;
	while(!S.empty())
	{
		std::pair<ll, ll> p = *S.begin();
		S.erase(p);
		ll u = p.second;
		if(!isMST[u])
		isMST[u] = 1;
		else continue;
		if(par[u])
		{
			tot += dist[u];
			T[u].pb(mp(par[u], dist[u]));
			T[par[u]].pb(mp(u, dist[u]));
		}	
		for(ll i=0,j=(ll)G[u].size();i<j;i++)
		{
			ll v = G[u][i].first;
			ll w = G[u][i].second;
			if(!isMST[v] && (dist[v] > w))
			{
				if(S.find(mp(dist[v], v)) != S.end())
				S.erase(mp(dist[v], v));
				S.insert(mp(w, v));
				par[v] = u;
				dist[v] = w;
			}	
		}	
	}
	return tot;	
}

void dfs_visit(ll s, ll p)
{
	if(p != -1)
	{
		lvl[s] = 1 + lvl[p];
		par[s] = p;
	}	
	for(ll i=0,j=(ll)T[s].size();i<j;i++)
	{
		ll u = T[s][i].first;
		ll w = T[s][i].second;
		if(u != p)
		{
			dist[u] = dist[s] + w;
			dfs_visit(u, s);
		}	
	}
	return;	
}

void ST_build(ll n)
{
	for(ll i=1;i<=n;i++)
	{
		for(ll j=0;(1LL<<j)<=n;j++)
		P[i][j] = -1;	
	}	
	for(ll i=1;i<=n;i++)
	{
		P[i][0] = par[i];
		mdst[i][0] = dist[i] - dist[par[i]];
	}	
	for(ll j=1;(1LL<<j)<=n;j++)
	{
		for(ll i=1;i<=n;i++)
		{
			if(P[i][j-1] != -1)
			{
				P[i][j] = P[P[i][j-1]][j-1];
				mdst[i][j] = std::max(mdst[i][j-1], mdst[P[i][j-1]][j-1]);
			}	
		}	
	}
	return;	
}

ll LCA_find(ll p, ll q)
{
	ll res = 0;
	if(lvl[p] < lvl[q])
	{
		int tmp = p;
		p = q;
		q = tmp;
	}	
	ll lx = 0;
	for(lx=1;(1LL<<lx)<=lvl[p];lx++);
	lx--;	
	for(ll i=lx;i>=0;i--)
	{
		if((lvl[p] - (1LL<<i)) >= lvl[q])
		{
			res = std::max(res, mdst[p][i]);
			p = P[p][i];
		}	
	}
	if(p == q)
	return res;
	for(ll i=lx;i>=0;i--)
	{
		if((P[p][i] != -1) && (P[p][i] != P[q][i]))
		{
			res = std::max(res, mdst[p][i]);
			res = std::max(res, mdst[q][i]);
			p = P[p][i];
			q = P[q][i];
		}	
	}
	res = std::max(res, mdst[p][0]);
	res = std::max(res, mdst[q][0]);
	return res;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll n,m;
	std::cin>>n>>m;
	for(ll i=0;i<m;i++)
	{
		ll s,d,w;
		std::cin>>s>>d>>w;
		G[s].pb(mp(d, w));
		G[d].pb(mp(s, w));
		E[i] = mp(mp(s, d), w);
	}
	ll tot = PrimMST(n);
	par[1] = 0;
	dist[1] = 0;
	dfs_visit(1, -1);
	ST_build(n);
	for(ll i=0;i<m;i++)
	{
		ll a = E[i].first.first;
		ll b = E[i].first.second;
		ll w = E[i].second;
		std::cout<<(tot - LCA_find(a, b) + w)<<"\n";
	}	
	return 0;
}