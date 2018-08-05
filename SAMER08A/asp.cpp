#include <bits/stdc++.h>
#define CHOR 501
#define INF 1000000000
#define mp std::make_pair

std::map<int, int> G[CHOR];
int dist[CHOR];
bool vis[CHOR];
std::set<std::pair<int, int> > par[CHOR];

int dijkstra_find(int s, int d, int n)
{
	for(int i=1;i<=n;i++)
	{
		dist[i] = INF;
		par[i].clear();
		vis[i] = 0;
	}	
	dist[s] = 0;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > P;
	P.push(mp(0, s));
	while(!P.empty())
	{
		std::pair<int, int> p = P.top();
		P.pop();
		int u = p.second;
		if(u == d)
		continue;
		vis[u] = 1;	
		for(std::map<int, int>::iterator it = G[u].begin();it != G[u].end();it++)
		{
			int v = it->first;
			int w = it->second;
			if(!vis[v] && (dist[v] >= dist[u] + w))
			{
				dist[v] = dist[u] + w;
				par[v].insert(mp(dist[v], u));
				P.push(mp(dist[v], v));
			}	
		}	
	}
	return dist[d];	
}

void delG(int s, int d, int sp)
{
	std::queue<std::pair<int, std::pair<int, int> > > Q;
	for(std::set<std::pair<int, int> >::iterator it = par[d].begin();it != par[d].end();it++)
	{
		if(it->first == sp)
		Q.push(mp(sp, mp(it->second, d)));	
	}	
	while(!Q.empty())
	{
		std::pair<int, std::pair<int, int> > p = Q.front();
		Q.pop();
		{
			
		}
		int u = p.second.first;
		int v = p.second.second;
		int w = G[u][v];
		if(u != s)
		{	
			for(std::set<std::pair<int, int> >::iterator it = par[u].begin();it != par[u].end();it++)
			{
				if(it->first == p.first - w)
				Q.push(mp(p.first - w, mp(it->second, u)));	
			}
		}
		G[u].erase(v);		
	}
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m;
	std::cin>>n>>m;
	while(n && m)
	{
		int s,d;
		std::cin>>s>>d;
		s++;
		d++;
		while(m--)
		{
			int u,v,w;
			std::cin>>u>>v>>w;
			u++;
			v++;
			G[u][v] = w;
		}
		int sp = dijkstra_find(s, d, n);
		delG(s, d, sp);
		sp = dijkstra_find(s, d, n);
		if(sp == INF)
		std::cout<<"-1\n";
		else std::cout<<sp<<"\n";
		for(int i=1;i<=n;i++)
		G[i].clear();	
		std::cin>>n>>m;	
	}	
	return 0;
}