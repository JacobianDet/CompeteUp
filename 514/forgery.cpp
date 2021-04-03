#include <bits/stdc++.h>

std::string G[1001];
bool X[1001][1001];

int main(void)
{
	int n,m;
	std::cin>>n>>m;
	for(int i=0;i<n;i++)
	std::cin>>G[i];
	bool ok = 1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(G[i][j] == '#')
			{
				if((i+2 < n) && (j+2 < m) && (G[i][j+1] == '#') && (G[i][j+2] == '#') && (G[i+1][j] == '#') && (G[i+1][j+2] == '#') && (G[i+2][j] == '#') && (G[i+2][j+1] == '#') && (G[i+2][j+2] == '#'))
				{
					X[i][j] = 1;
					X[i][j+1] = 1;
					X[i][j+2] = 1;
					X[i+1][j] = 1;
					X[i+1][j+2] = 1;
					X[i+2][j] = 1;
					X[i+2][j+1] = 1;
					X[i+2][j+2] = 1;
				}
				else if(!X[i][j])
				{	
					ok = 0;
					break;
				}		
			}	
		}
		if(!ok)	
		break;	
	}	
	if(!ok)
	std::cout<<"NO\n";
	else std::cout<<"YES\n";
	return 0;	
}