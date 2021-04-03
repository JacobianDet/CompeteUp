#include <bits/stdc++.h>
#define mp std::make_pair

std::pair<int, int> NE[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool vis[2001][2001];
std::pair<int, int> rem[2001][2001];

std::string G[2001];

void bfs_visit(int n, int m, int r, int c, int lx, int rx)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		vis[i][j] = 0;
	}
	std::deque<std::pair<int, int> > D;
	D.push_front(mp(r-1, c-1));
	rem[r-1][c-1] = mp(lx, rx);
	vis[r-1][c-1] = 1;
	while(!D.empty())
	{
		std::pair<int, int> p = D.front();
		D.pop_front();
		int x = p.first;
		int y = p.second;
		for(int i=0;i<4;i++)
		{
			int cx = x + NE[i].first;
			int cy = y + NE[i].second;
			if((0 <= cx) && (cx < n) && (0 <= cy) && (cy < m) && (G[cx][cy] != '*') && (!vis[cx][cy]))
			{
				if((i == 2) || (i == 3))
				{	
					vis[cx][cy] = 1;
					D.push_front(mp(cx, cy));
					rem[cx][cy] = rem[x][y];
				}	
				else if(!i && rem[x][y].first)
				{	
					vis[cx][cy] = 1;
					D.push_back(mp(cx, cy));
					rem[cx][cy] = mp(rem[x][y].first - 1, rem[x][y].second);
				}	
				else if((i == 1) && rem[x][y].second)
				{	
					vis[cx][cy] = 1;
					D.push_back(mp(cx, cy));
					rem[cx][cy] = mp(rem[x][y].first, rem[x][y].second - 1);
				}		
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
	int n,m,r,c,x,y;
	std::cin>>n>>m>>r>>c>>x>>y;
	for(int i=0;i<n;i++)
	std::cin>>G[i];
	bfs_visit(n, m, r, c, x, y);	
	int ctx = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			//std::cout<<vis[i][j]<<" ";
			if(vis[i][j])
			ctx++;	
		}	
		//std::cout<<"\n";
	}
	std::cout<<ctx<<"\n";
	return 0;
}