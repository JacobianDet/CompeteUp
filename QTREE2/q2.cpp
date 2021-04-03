#include <bits/stdc++.h>
#define CHOR 10001
#define pb push_back
#define mp std::make_pair

typedef long long ll;

std::vector<std::pair<ll, ll> > G[CHOR];
ll dist[CHOR];
ll lvl[CHOR];
ll par[CHOR];
ll P[CHOR][15];

void dfs_visit(ll s, ll p)
{
	lvl[s] = 0;
	par[s] = 0;
	if(p != -1)
	{
		lvl[s] = (1 + lvl[p]);
		par[s] = p;
	}	
	for(ll i=0,j=(ll)G[s].size();i<j;i++)
	{
		ll u = G[s][i].first;
		ll w = G[s][i].second;
		if(u != p)
		{
			dist[u] = w + dist[s];
			dfs_visit(u, s);
		}	
	}
	return;	
}

class ST
{
	public: void build(ll n);
			ll query(ll s, ll k);
};

void ST::build(ll n)
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

ll ST::query(ll s, ll k)
{
	ll lx = 0;
	for(lx=1;(1LL<<lx)<=k;lx++);
	lx--;
	for(ll i=lx;i>=0;i--)
	{
		if((k - (1LL<<i)) >= 0)
		{
			s = P[s][i];
			k -= (1LL<<i);
		}	
	}	
	return s;
}

ll LCA_find(ll p, ll q)
{
	if(lvl[p] < lvl[q])
	{
		ll tmp = p;
		p = q;
		q = tmp;
	}	
	ll l2 = 0;
	for(l2=1;(1LL<<l2)<=lvl[p];l2++);
	l2--;
	for(ll i=l2;i>=0;i--)
	{
		if((lvl[p] - (1LL<<i)) >= lvl[q])
		p = P[p][i];	
	}	
	if(p == q)
	return p;
	for(ll i=l2;i>=0;i--)
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
	ll T;
	std::cin>>T;
	while(T--)
	{
		ll n;
		std::cin>>n;
		for(ll i=0;i<n-1;i++)
		{
			ll s,d,w;
			std::cin>>s>>d>>w;
			G[s].pb(mp(d, w));
			G[d].pb(mp(s, w));
		}
		dfs_visit(1, -1);
		ST Z;
		Z.build(n);
		std::string s;
		std::cin>>s;
		while(s != "DONE")
		{
			if(s == "DIST")
			{
				ll a, b;
				std::cin>>a>>b;
				ll lca = LCA_find(a, b);
				std::cout<<(dist[a] + dist[b] - 2*dist[lca])<<"\n";
			}	
			else 
			{
				ll a,b,k;
				std::cin>>a>>b>>k;
				k--;
				ll lca = LCA_find(a, b);
				if(k <= (lvl[a] - lvl[lca]))
				std::cout<<Z.query(a, k)<<"\n";
				else std::cout<<Z.query(b, (lvl[a] + lvl[b] - 2*lvl[lca] - k))<<"\n";	
			}
			std::cin>>s;	
		}
		std::cout<<"\n";
		for(ll i=1;i<=n;i++)
		G[i].clear();	
	}
	return 0;	
}