#include <bits/stdc++.h>

std::string G[1001];
bool vis[1001][1001];

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		memset(vis, 0, sizeof(vis));
		int n,m;
		std::cin>>n>>m;
		for(int i=0;i<n;i++)
		std::cin>>G[i];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if((0 <= i+1) && (i+1 < n) && (0 <= j+1) && (j+1 < m) && (G[i][j] == '.') && (G[i+1][j] == '.') && (G[i][j+1] == '.') && (G[i+1][j+1] == '.'))
				{
					vis[i][j] = 1;
					vis[i+1][j] = 1;
					vis[i][j+1] = 1;
					vis[i+1][j+1] = 1;
				}	
			}	
		}
		bool ok = 1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if((G[i][j] == '.') && !vis[i][j])
				{
					ok = 0;
					break;
				}	
			}
			if(!ok)
			break;	
		}	
		if(ok)
		std::cout<<"YES\n";
		else std::cout<<"NO\n";	
	}
	return 0;
}