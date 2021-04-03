#include <bits/stdc++.h>

char G[1000][1000];
bool vis[1000][1000][5][3];
int n,m;

std::pair<int, int> NE[4] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

bool dfs_visit(int x, int y, int p, int turn)
{	
	if(turn > 2 || vis[x][y][p][turn])
	return false;
	if(G[x][y] == 'T')
	return true;
	bool r = false;
	vis[x][y][p][turn] = true;
	for(int i=0;i<4;i++)
	{
		int u = NE[i].first;
		int v = NE[i].second;
		int cx = x + u;
		int cy = y + v;
		if(0 <= cx && cx < n && 0 <= cy && cy < m && G[cx][cy] != '*')
		{
			if(p == 4 || p == i)
			r |= dfs_visit(cx, cy, i, turn);
			else r |= dfs_visit(cx, cy, i, turn + 1);	
		}	
	}
	return r;	
}

int main(void)
{
	memset(G,'.',sizeof(G));
	memset(vis,false,sizeof(vis));
	std::cin>>n>>m;
	int x,y;
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
		}	
	}	
	bool r = dfs_visit(x, y, 4, 0);
	if(r)
	std::cout<<"YES\n";
	else std::cout<<"NO\n";
	return 0;	
}