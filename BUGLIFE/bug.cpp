#include <bits/stdc++.h>
#define pb push_back
#define CHOR 2001

int col[2001];

void dfs_visit(std::vector<std::vector<int> >& G, int s, int p, int &c)
{
	for(int i=0,j=G[s].size();i<j;i++)
	{
		if(!col[G[s][i]])
		{
			col[G[s][i]] = col[p];
			dfs_visit(G, G[s][i], s, c);
		}	
		else if(col[G[s][i]] == col[s])
		c++;	
	}	
	return;
}

int main(void)
{
	int T;
	std::cin>>T;
	for(int i=1;i<=T;i++)
	{
		std::vector<std::vector<int> > G(CHOR);
		memset(col,0,sizeof(col));
		int n,m;
		std::cin>>n>>m;
		for(int j=0;j<m;j++)
		{
			int s,d;
			std::cin>>s>>d;
			G[s].pb(d);
			G[d].pb(s);
		}
		col[0] = 2;
		int c = 0;
		for(int j=1;j<=n;j++)
		{
			if(!col[j])
			{	
				col[j] = 1;
				dfs_visit(G, j, 0, c);
			}		
		}	
		std::cout<<"Scenario #"<<i<<":\n";
		if(!c)
		std::cout<<"No suspicious bugs found!\n";
		else std::cout<<"Suspicious bugs found!\n";	
	}
	return 0;	
}