#include <bits/stdc++.h>

bool G[1001][1001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m;
	std::cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int s,d;
		std::cin>>s>>d;
		G[s][d] = 1;
	}
	for(int i=1;i<=n;i++)
	G[i][i] = 1;	
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			G[i][j] |= (G[i][k] & G[k][j]);	
		}
	}	
	int ax = 0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(!G[i][j])
			ax++;
		}	
	}
	std::cout<<ax<<"\n";
	return 0;
}