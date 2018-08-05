#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair
#define INF 1e12

typedef long long ll;

std::vector<std::pair<ll, ll> > G[1001];

ll mst_prim(ll n)
{
	std::vector<ll> key(n+1, INF);
	std::vector<bool> isM(n+1, 0);
	std::set<std::pair<ll, ll> > s;
	s.insert(mp(0, 1));
	key[1] = 0;
	ll total = 0;
	for(int i=1;i<=n;i++)
	{
		std::pair<ll, ll> p = *(s.begin());
		s.erase(p);
		ll u = p.second;
		isM[u] = 1;
		total += key[u];
		for(ll j=0,k=(ll)G[u].size();j<k;j++)
		{
			ll v = G[u][j].first;
			ll w = G[u][j].second;
			if((key[v] > w) && (!isM[v]))
			{
				if(s.find(mp(key[v], v)) != s.end())
				s.erase(mp(key[v], v));
				s.insert(mp(w, v));
				key[v] = w;	
			}	
		}	
	}
	return total;	
}

int main(void)
{
	ll t;
	std::cin>>t;
	while(t--)
	{
		ll p,n,m;
		std::cin>>p>>n>>m;
		for(ll i=0;i<m;i++)
		{
			ll s,d,w;
			std::cin>>s>>d>>w;
			G[s].pb(mp(d, w));
			G[d].pb(mp(s, w));
		}
		ll total = mst_prim(n);	
		std::cout<<p*total<<"\n";
		for(int i=1;i<=1000;i++)
		G[i].clear();	
	}	
	return 0;
}