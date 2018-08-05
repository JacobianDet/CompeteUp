#include <bits/stdc++.h>
#define pb push_back

std::vector<int> G[1001];
int lvl[1001], par[1001];
int P[1001][11];

void dfs_visit(int s, int p)
{
	par[s] = 0;
	lvl[s] = 0;
	if(p != -1)
	{	
		par[s] = p;
		lvl[s] += (1 + lvl[p]);
	}
	for(int i=0,j=(int)G[s].size();i<j;i++)
	{
		if(G[s][i] != p)
		dfs_visit(G[s][i], s);	
	}	
	return;	
}

void ST_build(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;(1<<j)<=n;j++)
		P[i][j] = -1;
	}
	for(int i=1;i<=n;i++)
	P[i][0] = par[i];
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(P[i][j-1] != -1)
			P[i][j] = P[P[i][j-1]][j-1];
		}	
	}
	return;	
}

int LCA_find(int p, int q)
{
	if(lvl[p] < lvl[q])
	{
		int tmp = p;
		p = q;
		q = tmp;
	}
	int l2 = 0;
	for(l2=1;(1<<l2)<=lvl[p];l2++);
	l2--;
	for(int i=l2;i>=0;i--)
	{
		if((lvl[p] - (1<<i)) >= lvl[q])
		p = P[p][i];	
	}	
	if(p == q)
	return p;	
	for(int i=l2;i>=0;i--)
	{
		if((P[p][i] != -1) && (P[p][i] != P[q][i]))
		{
			p = P[p][i];
			q = P[q][i];
		}
	}	
	return par[p];
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{	
		int n;
		std::cin>>n;
		for(int i=1;i<=n;i++)
		{
			int m;
			std::cin>>m;
			while(m--)
			{
				int d;
				std::cin>>d;
				G[i].pb(d);
				G[d].pb(i);
			}	
		}
		dfs_visit(1, -1);
		ST_build(n);
		int q;
		std::cin>>q;
		std::cout<<"Case "<<t<<":\n";
		while(q--)
		{
			int v,w;
			std::cin>>v>>w;
			std::cout<<LCA_find(v, w)<<"\n";
		}
		for(int i=1;i<=n;i++)
		G[i].clear();	
	}	
	return 0;
}