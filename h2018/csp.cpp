#include <bits/stdc++.h>
#define pb push_back

std::vector<std::vector<int> > G(1001);
std::vector<int> lc(1001);

void dfs_visit(int s)
{
	for(int i=0,j=(int)G[s].size();i<j;i++)
	{
		dfs_visit(G[s][i]);
		if(!lc[G[s][i]])
		lc[s]++;	
	}	
	return;
}


int main(void)
{
	int n;
	std::cin>>n;
	for(int i=2;i<=n;i++)
	{
		int p;
		std::cin>>p;
		G[p].pb(i);
	}	
	dfs_visit(1);
	int ctr=0;
	for(int i=1;i<=n;i++)
	{
		if((lc[i] > 0 && lc[i] < 3) || (G[i].size() && !lc[i]))
		ctr++;
	}	
	if(!ctr)
	std::cout<<"Yes\n";
	else std::cout<<"No\n";
	return 0;	
}