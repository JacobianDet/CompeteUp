#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair
#define INF 1000000001

struct rzx
{
	int dis, s;
	bool operator < (const rzx& zx) const
	{
		return (dis > zx.dis);
	}
};	

std::vector<std::pair<int, int> > G[100001];
int dist[100001];
bool vis[100001];
std::set<int> FZ[100001];

int dijkstra_find(int n, int u, int v)
{
	for(int i=1;i<=n;i++)
	{
		dist[i] = INF;	
		vis[i] = 0;
	}	
	dist[u] = 0;
	std::priority_queue<rzx> P;
	P.push({0, u});
	while(!P.empty())
	{
		rzx px = P.top();
		P.pop();
		int s = px.s;
		if(vis[s] || (s == v))
		continue;
		vis[s] = 1;
		for(int i=0,j=(int)G[s].size();i<j;i++)
		{
			if((FZ[s].find(G[s][i].second) != FZ[s].end()) || (s == u))
			{
				if(dist[G[s][i].first] > dist[s])
				{
					FZ[G[s][i].first].clear();
					FZ[G[s][i].first].insert(G[s][i].second);
					dist[G[s][i].first] = dist[s];
					P.push({dist[G[s][i].first], G[s][i].first});	
				}
				else if(dist[G[s][i].first] == dist[s])
				FZ[G[s][i].first].insert(G[s][i].second);
				
			}
			else
			{
				if(dist[G[s][i].first] > dist[s] + 1)
				{
					FZ[G[s][i].first].clear();
					FZ[G[s][i].first].insert(G[s][i].second);
					dist[G[s][i].first] = dist[s] + 1;
					P.push({dist[G[s][i].first], G[s][i].first});	
				}
				else if(dist[G[s][i].first] == dist[s] + 1)
				FZ[G[s][i].first].insert(G[s][i].second);
			}	
		}
		FZ[s].clear();
	}
	return dist[v];
}	

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m;
	std::cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int s,d,w;
		std::cin>>s>>d>>w;
		G[s].pb(mp(d, w));
		G[d].pb(mp(s, w));
	}
	int u,v;
	std::cin>>u>>v;
	int ans = dijkstra_find(n, u, v);	
	std::cout<<ans<<"\n";
	return 0;
}	
