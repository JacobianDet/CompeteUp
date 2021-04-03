#include <bits/stdc++.h>
#define pb push_back
#define CHOR 100001
#define INF 1000000000

typedef long long ll;

int arr[CHOR],n;
int lvl[CHOR][101];
std::vector<int> G[CHOR];

void bfs_visit(int k)
{
	std::queue<int> Q;
	for(int i=1;i<=n;i++)
	{
		if(arr[i] == k)
		{	
			lvl[i][k] = 0;
			Q.push(i);	
		}	
	}
	while(!Q.empty())
	{
		int s = Q.front();
		Q.pop();
		for(int i=0,j=(int)G[s].size();i<j;i++)
		{
			if(lvl[G[s][i]][k] > lvl[s][k] + 1)
			{
				lvl[G[s][i]][k] = lvl[s][k] + 1;
				Q.push(G[s][i]);
			}	
		}	
	}
	return;	
}

int main(void)
{	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int m,k,s;
	std::cin>>n>>m>>k>>s;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		lvl[i][j] = INF;	
	}	
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	for(int i=0;i<m;i++)
	{
		int s,d;
		std::cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}	
	for(int i=1;i<=k;i++)
	bfs_visit(i);
	for(int i=1;i<=n;i++)
	{	
		std::sort(lvl[i]+1, lvl[i]+k+1);
		ll sum = 0;
		for(int j=1;j<=s;j++)
		sum += lvl[i][j];
		std::cout<<sum<<" ";
	}	
	std::cout<<"\n";
	return 0;
}