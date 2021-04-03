#include <bits/stdc++.h>
#define mp std::make_pair

std::pair<int, int> NE[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct amma
{
	int sh,wv;
	bool bk;
};

std::string G[250];
bool vis[250][250];
int n,m;

amma dfs_visx(int x, int y)
{
	vis[x][y] = 1;
	if(x == n-1 || y == m-1)
	{
		int sh = 0, wv = 0;
		bool bk = 1;
		if(G[x][y] == 'k')
		sh++;
		else if(G[x][y] == 'v')
		wv++;
		return {sh, wv, bk};
	}
	int sh = 0, wv = 0;
	bool bk = 0;
	for(int i=0;i<4;i++)
	{
		int cx = x + NE[i].first;
		int cy = y + NE[i].second;
		if(0 <= cx && cx < n && 0 <= cy && cy < m && G[cx][cy] != '#' && !vis[cx][cy])
		{
			amma p = dfs_visx(cx, cy);
			sh += p.sh;
			wv += p.wv;
			bk |= p.bk;
		}	
	}	
	if(G[x][y] == 'k')
	sh++;
	else if(G[x][y] == 'v')
	wv++;
	return {sh, wv, bk};	
}

int main(void)
{
	std::cin>>n>>m;
	for(int i=0;i<n;i++)
	std::cin>>G[i];
	int sh = 0, wv = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!vis[i][j])
			{
				amma p = dfs_visx(i, j);
				if(!p.bk)
				{
					if(p.sh > p.wv)
					sh += p.sh;
					else wv += p.wv;	
				}	
				else
				{
					sh += p.sh;
					wv += p.wv;
				}	
			}	
		}
	}
	std::cout<<sh<<" "<<wv<<"\n";
	return 0;	
}