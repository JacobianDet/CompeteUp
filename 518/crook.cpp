#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

std::pair<int, int> arr[1001];
int G[2001][2001];
std::vector<std::pair<int, int> > anx[1001];

int main(void)
{
	int n,m;
	std::cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int s,d;
		std::cin>>s>>d;
		arr[i] = mp(s, d);
	}	
	for(int i=1;i<=n;i++)
	G[i][i] = i;
	for(int i=0;i<m;i++)
	{
		int s = arr[i].first;
		int d = arr[i].second;
		G[n+1+i][s] = s;
		G[d][n+1+i] = d;
		G[n+1+i][n+1+i] = s;
	}	
	for(int i=1;i<=n+m;i++)
	{
		for(int j=1;j<=n+m;j++)
		{
			if(G[i][j])
			anx[G[i][j]].pb(mp(i, j));	
		}	
	}	
	for(int i=1;i<=n;i++)
	{
		std::cout<<(int)anx[i].size()<<"\n";
		for(int j=0,k=(int)anx[i].size();j<k;j++)
		std::cout<<anx[i][j].first<<" "<<anx[i][j].second<<"\n";
	}	
	return 0;
}