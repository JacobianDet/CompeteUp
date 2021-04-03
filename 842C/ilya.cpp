#include <bits/stdc++.h>
#define pb push_back
#define CHOR 200001

std::vector<std::vector<int> > G(CHOR);
int col[CHOR];
int mcol[CHOR];
int zcol[CHOR];

void dfs_visit(int s, int p, bool z)
{
	
	return;
}

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>col[i];
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		std::cin>>s>>d;
		G[s].pb(d);
	}	
	dfs_visit(1, 0, 0);
	for(int i=1;i<=n;i++)
	std::cout<<zcol[i]<<" ";
	std::cout<<"\n";
	return 0;	
}