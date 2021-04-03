#include <bits/stdc++.h>

int pref[301][301][11];

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int x;
			std::cin>>x;
			pref[i][j][x]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int x=1;x<=10;x++)
			pref[i][j][x] += pref[i][j-1][x];
		}	
	}	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int x=1;x<=10;x++)
			pref[j][i][x] += pref[j-1][i][x];	
		}	
	}
	int q;
	std::cin>>q;
	while(q--)
	{
		int x1, y1, x2, y2;
		std::cin>>x1>>y1>>x2>>y2;
		int ctx = 0;
		for(int x=1;x<=10;x++)
		{
			if((pref[x2][y2][x] - pref[x1-1][y2][x] - pref[x2][y1-1][x] + pref[x1-1][y1-1][x]) > 0)
			ctx++;	
		}
		std::cout<<ctx<<"\n";
	}
	return 0;
}