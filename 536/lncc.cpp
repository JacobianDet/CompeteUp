#include <bits/stdc++.h>

std::string G[501];

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>G[i];
	int cc = 0;
	for(int i=1;i<n-1;i++)
	{
		for(int j=1;j<n-1;j++)
		{
			if(G[i][j] == 'X' && G[i-1][j-1] == 'X' && G[i-1][j+1] == 'X' && G[i+1][j-1] == 'X' && G[i+1][j+1] == 'X')
			cc++;	
		}
	}
	std::cout<<cc<<"\n";
	return 0;
}