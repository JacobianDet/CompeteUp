#include <bits/stdc++.h>
#define INF 100000000000
#define mp std::make_pair

typedef long long ll;

ll G[101][101];
std::pair<int, int> op[13];
ll dist[101][101];
ll memo[101][(1<<12)];
int vis[101][(1<<12)];
int b;

int dfx(int n, int mask, int t)
{
	if(!mask)
	return dist[n][b];
	if(vis[n][mask] == t)
	return memo[n][mask];
	ll ans = INF;
	for(int i=0;i<12;i++)
	{
		if(mask & (1<<i))
		ans = std::min(ans, dist[n][op[i+1].first] + dist[op[i+1].first][op[i+1].second] + dfx(op[i+1].second, (mask ^ (1<<i)), t));	
	}	
	memo[n][mask] = ans;
	vis[n][mask] = t;
	return ans;
}

int main(void)
{
	memset(vis, 0, sizeof(vis));
	memset(memo, -1, sizeof(memo));
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n,m;
		std::cin>>n>>m>>b;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i != j)
				{
					G[i][j] = INF;
					dist[i][j] = INF;
				}		
			}	
		}	
		for(int i=0;i<m;i++)
		{
			int u,v,w;
			std::cin>>u>>v>>w;
			if(G[u][v] > w)
			G[u][v] = 1LL*w;
			if(G[v][u] > w)
			G[v][u] = 1LL*w;	
		}
		for(int k=0;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(!k)
					dist[i][j] = G[i][j];
					else dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
				}	
			}
		}	
		int z;
		std::cin>>z;
		int ox = 0;
		for(int i=0;i<z;i++)
		{
			int u,v,d;
			std::cin>>u>>v>>d;
			for(int i=1;i<=d;i++)
			{
				ox++;
				op[ox] = mp(u, v);
			}
		}
		ll ans = dfx(b, (1<<ox)-1, t);
		std::cout<<ans<<"\n";
	}
	return 0;
}