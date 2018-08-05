#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

std::string G[182];
int lx[182][182];
int n,m;

std::pair<int, int> NE[4] = {{0,-1}, {0, 1}, {-1, 0}, {1, 0}};

void bfs_visit(int s1, int s2)
{
	lx[s1][s2] = 0;
	std::queue<std::pair<int, int> > Q;
	Q.push(mp(s1, s2));
	while(!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		for(int i=0;i<4;i++)
		{
			int u = NE[i].first;
			int v = NE[i].second;
			int cx = x + u;
			int cy = y + v;
			if(cx >= 0 && cx < n && cy >= 0 && cy < m && lx[cx][cy] > lx[x][y] + 1 && G[cx][cy] != '1')
			{
				lx[cx][cy] = lx[x][y] + 1;
				Q.push(mp(cx, cy));
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
		for(int i=0;i<182;i++)
		{
			for(int j=0;j<182;j++)
			lx[i][j] = 1e7;	
		}	
		std::cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			std::cin>>G[i];	
		}	
		std::vector<std::pair<int, int> > Z;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(G[i][j] == '1')
				Z.pb(mp(i, j));	
			}	
		}	
		for(int i=0,j=(int)Z.size();i<j;i++)
		bfs_visit(Z[i].first, Z[i].second);		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			std::cout<<lx[i][j]<<" ";
			std::cout<<"\n";	
		}	
	}	
	return 0;
}