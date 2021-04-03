#include <bits/stdc++.h>
#define mp std::make_pair
#define pb push_back
#define INF 1000000000000
#define CHOR 100001

typedef long long ll;

struct trx
{
	int u;
	ll w;
	int m;
};

std::vector<trx> G[CHOR];
ll dist[CHOR];
bool vis[CHOR];
int par[CHOR];
bool tmx[CHOR];

void dijkstra_find(int s, int n)
{
	for(int i=1;i<=n;i++)
	{
		tmx[i] = 0;
		vis[i] = 0;
		par[i] = -1;
		dist[i] = INF;
	}
	std::priority_queue<std::pair<ll, int>, std::vector<std::pair<ll, int> >, std::greater<std::pair<ll, int> > > P;
	dist[s] = 0;
	P.push(mp(0, s));
	while(!P.empty())
	{
		std::pair<ll, int> p = P.top();
		P.pop();
		int u = p.second;
		if(dist[u] < p.first)
		continue;
		vis[u] = 1;
		for(int i=0,j=(int)G[u].size();i<j;i++)
		{
			int v = G[u][i].u;
			ll w = G[u][i].w;
			int mx = G[u][i].m;
			if(!vis[v])
			{
				if(dist[v] > dist[u] + w)
				{
					dist[v] = dist[u] + w;
					par[v] = u;
					P.push(mp(dist[v], v));
					tmx[v] = mx;
				}
				else if(!mx && (dist[v] == dist[u] + w))
				tmx[v] = mx;	
			}
		}
	}
	return;
}

int main(void)
{	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m,k;
	std::cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		int u,v;
		ll w;
		std::cin>>u>>v>>w;
		G[u].pb({v, w, 0});
		G[v].pb({u, w, 0});
	}
	for(int i=0;i<k;i++)
	{
		int u;
		ll w;
		std::cin>>u>>w;
		G[1].pb({u, w, 1});
		G[u].pb({1, w, 1});
	}
	dijkstra_find(1, n);
	int ans = k;
	for(int i=1;i<=n;i++)
	{
		if(tmx[i])
		ans--;
	}
	std::cout<<ans<<"\n";
	return 0;
}