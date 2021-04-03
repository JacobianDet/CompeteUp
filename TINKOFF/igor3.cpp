#include <bits/stdc++.h>
#define INF 1e7

struct dins
{
	int x,y,d;
};

char G[1000][1000];
int dist[1000][1000][5];
int n,m;
std::pair<int, int> NE[4] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

void bfs_01(int x, int y, int d)
{
	dist[x][y][d] = 0;
	std::deque<dins> D;
	D.push_front({x, y, d});
	while(!D.empty())
	{
		dins t = D.front();
		D.pop_front();
		if(G[t.x][t.y] == 'T')
		continue;	
		for(int i=0;i<4;i++)
		{
			int u = NE[i].first;
			int v = NE[i].second;
			int cx = t.x + u;
			int cy = t.y + v;
			int e = 0;
			if(0 <= cx && cx < n && 0 <= cy && cy < m && G[cx][cy] != '*')
			{
				if(t.d == 4 || t.d == i)
				e = 0;
				else e = 1;
				if(dist[t.x][t.y][t.d] + e < dist[cx][cy][i])
				{
					dist[cx][cy][i] = dist[t.x][t.y][t.d] + e;
					if(e)
					D.push_back({cx, cy, i});
					else D.push_front({cx, cy, i});	
				}	
			}	
		}	
	}
	return;	
}

int main(void)
{
	memset(G,'.',sizeof(G));
	for(int i=0;i<1000;i++)
	{
		for(int j=0;j<1000;j++)
		{
			for(int k=0;k<4;k++)
			dist[i][j][k] = INF;	
		}		
	}	
	std::cin>>n>>m;
	int x=0,y=0,fx=0,fy=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			std::cin>>G[i][j];
			if(G[i][j] == 'S')
			{
				x = i;
				y = j;
			}	
			if(G[i][j] == 'T')
			{
				fx = i;
				fy = j;
			}	
		}	
	}
	bfs_01(x, y, 4);
	int z = std::min(dist[fx][fy][0], std::min(dist[fx][fy][1], std::min(dist[fx][fy][2], dist[fx][fy][3])));
	if(z > 2)
	std::cout<<"NO\n";
	else std::cout<<"YES\n";	
	return 0;
}