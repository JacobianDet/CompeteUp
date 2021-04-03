#include <bits/stdc++.h>
#define mp std::make_pair
#define pf push_front
#define pb push_back
#define pof pop_front
#define INF 1e7

char G[1000][1000];
int dist[1000][1000];
int r,c;
std::pair<int, int> NE[4] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

void bfs_01(int x, int y)
{
	dist[x][y] = 0;
	std::deque<std::pair<int, int> > D;
	D.pf(mp(x, y));
	while(!D.empty())
	{
		std::pair<int, int> t = D.front();
		D.pof();
		if(t.first == r-1 && t.second == c-1)
		continue;	
		for(int i=0;i<4;i++)
		{
			int u = NE[i].first;
			int v = NE[i].second;
			int cx = t.first + u;
			int cy = t.second + v;
			int e = 0;
			if(0 <= cx && cx < r && 0 <= cy && cy < c)
			{
				if(G[cx][cy] == G[t.first][t.second])
				e = 0;
				else e = 1;
				if(dist[t.first][t.second] + e < dist[cx][cy])
				{
					dist[cx][cy] = dist[t.first][t.second] + e;
					if(e)
					D.pb(mp(cx, cy));
					else D.pf(mp(cx, cy));	
				}	
			}	
		}	
	}	
	return;
}

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		for(int i=0;i<1000;i++)
		{
			for(int j=0;j<1000;j++)
			dist[i][j] = INF;
		}	
		std::cin>>r>>c;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			std::cin>>G[i][j];	
		}	
		bfs_01(0, 0);
		std::cout<<dist[r-1][c-1]<<"\n";
	}	
	return 0;
}