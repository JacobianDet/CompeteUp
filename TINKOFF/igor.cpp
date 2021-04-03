#include <bits/stdc++.h>
#define CHOR 50000

//WRONG SOLUTION

char G[1000][1000];
bool vis[1000][1000];
int sp[1000][1000][25][5];
int n,m;
std::pair<int, int> NE[24][4] = {{{0, -1}, {0, 1}, {1, 0}, {-1, 0}},
								 {{0, -1}, {0, 1}, {-1, 0}, {1, 0}},
								 {{0, -1}, {1, 0}, {0, 1}, {-1, 0}},
								 {{0, -1}, {1, 0}, {-1, 0}, {0, 1}},
								 {{0, -1}, {-1, 0}, {0, 1}, {1, 0}},
								 {{0, -1}, {-1, 0}, {1, 0}, {0, 1}},
								 {{0, 1}, {-1, 0}, {1, 0}, {0, -1}},
								 {{0, 1}, {-1, 0}, {0, -1}, {1, 0}},
								 {{0, 1}, {1, 0}, {0, -1}, {-1, 0}},
								 {{0, 1}, {1, 0}, {-1, 0}, {0, -1}},
								 {{0, 1}, {0, -1}, {-1, 0}, {1, 0}},
								 {{0, 1}, {0, -1}, {1, 0}, {-1, 0}},
								 {{-1, 0}, {0, -1}, {1, 0}, {0, 1}},
								 {{-1, 0}, {0, -1}, {0, 1}, {1, 0}},
								 {{-1, 0}, {0, 1}, {0, -1}, {1, 0}},
								 {{-1, 0}, {0, 1}, {1, 0}, {0, -1}},
								 {{-1, 0}, {1, 0}, {0, -1}, {0, 1}},
								 {{-1, 0}, {1, 0}, {0, 1}, {0, -1}},
								 {{1, 0}, {-1, 0}, {0, 1}, {0, -1}},
								 {{1, 0}, {-1, 0}, {0, -1}, {0, 1}},
								 {{1, 0}, {0, -1}, {-1, 0}, {0, 1}},
								 {{1, 0}, {0, -1}, {0, 1}, {-1, 0}},
								 {{1, 0}, {0, 1}, {-1, 0}, {0, -1}},
								 {{1, 0}, {0, 1}, {0, -1}, {-1, 0}}}; 

int dfs_visit(int x, int y, int a, int b)
{
	if(G[x][y] == 'T')
	return 0;	
	if(sp[x][y][a][b] != -1)
	return sp[x][y][a][b];
	vis[x][y] = 1;	
	int turn = CHOR;
	for(int i=0;i<24;i++)
	{	
		for(int j=0;j<4;j++)
		{
			int u = NE[i][j].first;
			int v = NE[i][j].second;
			int cx = x + u;
			int cy = y + v;
			if(0 <= cx && cx < n && 0 <= cy && cy < m && G[cx][cy] != '*' && !vis[cx][cy])
			{
				if((a == 24 && b == 4) || (NE[a][b].first == u && NE[a][b].second == v))
				turn = std::min(turn, dfs_visit(cx, cy, i, j));
				else turn = std::min(turn, 1 + dfs_visit(cx, cy, i, j));
			}	
		}
	}		
	sp[x][y][a][b] = turn;
	vis[x][y] = 0;
	return turn;
}

int main(void)
{
	memset(G,'.',sizeof(G));
	memset(vis,false,sizeof(vis));
	memset(sp,-1,sizeof(sp));
	std::cin>>n>>m;
	int x,y;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			char z;
			std::cin>>z;
			G[i][j] = z;
			if(G[i][j] == 'S')
			{
				x = i;
				y = j;
			}
		}	
	}
	int turn = dfs_visit(x, y, 24, 4);	
	if(turn > 2)
	std::cout<<"NO\n";
	else std::cout<<"YES\n";	
	return 0;	
}