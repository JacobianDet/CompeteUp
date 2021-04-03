#include <bits/stdc++.h>
#define mp std::make_pair

std::pair<int, int> NE[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, 0}, {1, -1}, {1, 1}};

int a[2], b[2], c[2];
bool vis[1001][1001];

void bfs_visit(int n)
{
	std::queue<std::pair<int, int> > Q;
	Q.push(mp(b[0], b[1]));
	while(!Q.empty())
	{
		std::pair<int, int> p = Q.front();
		Q.pop();
		int x = p.first;
		int y = p.second;
		if(vis[x][y] || ((x == c[0]) && (y == c[1])))
		{	
			vis[x][y] = 1;
			continue;
		}	
		vis[x][y] = 1;
		for(int i=0;i<8;i++)
		{
			int cx = x + NE[i].first;
			int cy = y + NE[i].second;
			if((0 < cx) && (cx <= n) && (0 < cy) && (cy <= n) && (a[0] != cx) && (a[1] != cy) && (abs(a[0] - cx) != abs(a[1] - cy)) && !vis[cx][cy])
			Q.push(mp(cx, cy));	
		}	
	}
	return;	
}

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<2;i++)
	std::cin>>a[i];
	for(int i=0;i<2;i++)
	std::cin>>b[i];
	for(int i=0;i<2;i++)
	std::cin>>c[i];
	bfs_visit(n);
	if(vis[c[0]][c[1]])
	std::cout<<"YES\n";
	else std::cout<<"NO\n";
	return 0;	
}