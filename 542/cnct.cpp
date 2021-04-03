#include <bits/stdc++.h>
#define mp std::make_pair
#define pb push_back

std::pair<int, int> NE[4] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
std::string G[50]; 
bool vis[50][50];
int vx[50][50];
std::vector<std::pair<int, int> > CC[2501];

void dfs_visit(int n, int x, int y, int ccx)
{
	vis[x][y] = 1;
	vx[x][y] = ccx;
	CC[ccx].pb(mp(x, y));
	for(int i=0;i<4;i++)
	{
		int cx = x + NE[i].first;
		int cy = y + NE[i].second;
		if(0 <= cx && cx < n && 0 <= cy && cy < n && G[cx][cy] != '1' && !vis[cx][cy])
		dfs_visit(n, cx, cy, ccx);	
	}	
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,r1,c1,r2,c2;
	std::cin>>n>>r1>>c1>>r2>>c2;
	r1--;
	c1--;
	r2--;
	c2--;
	for(int i=0;i<n;i++)
	std::cin>>G[i];
	int ccx = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(G[i][j] != '1' && !vis[i][j])
			{	
				ccx++;
				dfs_visit(n, i, j, ccx);
			}		
		}	
	}	
	if(vx[r1][c1] == vx[r2][c2])
	std::cout<<"0\n";
	else
	{
		int ans = 100000000;
		for(auto u : CC[vx[r1][c1]])
		{
			for(auto v : CC[vx[r2][c2]])
			ans = std::min(ans, (u.first - v.first) * (u.first - v.first) + (u.second - v.second) * (u.second - v.second));
		}	
		std::cout<<ans<<"\n";
	}	
	return 0;
}