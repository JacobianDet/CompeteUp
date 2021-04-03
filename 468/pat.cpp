#include <bits/stdc++.h>
#define pb push_back

std::vector<std::vector<int> > G(100001);
int lvl[100001];
int lvc[100001];

void dfs_visit(int s)
{
	for(int i=0,j=(int)G[s].size();i<j;i++)
	{
		lvl[G[s][i]] = lvl[s]+1;
		dfs_visit(G[s][i]);
	}	
	return;
}

int main(void)
{
	int n;
	std::cin>>n;
	for (int i=2;i<=n;i++)
	{
		int p;
		std::cin>>p;
		G[p].pb(i);
	}
	dfs_visit(1);
	int ans = 0;
	for(int i=1;i<=n;i++)
	lvc[lvl[i]]++;
	for(int i=0;i<=100000;i++)
	ans = ans + lvc[i]%2;
	std::cout<<ans<<"\n";
	return 0;
}