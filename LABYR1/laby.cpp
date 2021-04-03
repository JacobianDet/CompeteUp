#include <bits/stdc++.h>
#define mp std::make_pair

std::pair<int, int> NE[4] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
std::string G[1000];

std::pair<int, int> dfs_visit(int r, int c, int x, int y, int px, int py)
{
	int n1 = 0, n2 = 0, g = 0, h = 0, ih = 0;
	for(int i=0;i<4;i++)
	{
		int cx = x + NE[i].first;
		int cy = y + NE[i].second;
		if(0 <= cx && cx < r && 0 <= cy && cy < c && (cx != px || cy != py) && G[cx][cy] == '.')
		{
			std::pair<int, int> p = dfs_visit(r, c, cx, cy, x, y);
			ih = 1 + p.second;
			if(ih > n1)
			{
				n2 = n1;
				n1 = ih;
			}	
			else if(ih <= n1 && ih > n2)
			n2 = ih;	
			if(n1 + n2 > p.first)
			{
				if(g < n1 + n2)
				g = n1 + n2;	
			}
			else 
			{
				if(g < p.first)
				g = p.first;	
			}
			h = std::max(h, ih);	
		}
	}		
	return mp(g, h);
}


int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int c,r;
		std::cin>>c>>r;
		for(int i=0;i<r;i++)
		std::cin>>G[i];
		int x1 = 0, y1 = 0;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(G[i][j] == '.')
				{
					x1 = i;
					y1 = j;
					break;
				}	
			}	
		}
		std::cout<<"Maximum rope length is "<<dfs_visit(r, c, x1, y1, -1, -1).first<<".\n";
	}	
	return 0;
}