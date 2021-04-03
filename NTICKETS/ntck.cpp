#include <bits/stdc++.h>
#define CHOR 500001
#define pb push_back
#define mp std::make_pair

std::vector<std::pair<int, int> > G[CHOR];
int lvl[CHOR], par[CHOR], me[CHOR];
int P[CHOR][20], mdst[CHOR][20];

void dfs_visit(int s, int p)
{
	if(p != -1)
	{
		lvl[s] = 1 + lvl[p];
		par[s] = p;
	}	
	for(int i=0,j=(int)G[s].size();i<j;i++)
	{
		int u = G[s][i].first;
		int w = G[s][i].second;
		if(u != p)
		{
			me[u] = w;
			dfs_visit(u, s);
		}	
	}	
	return;
}

void ST_build(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;(1<<j)<=n;j++)
		{	
			P[i][j] = -1;
			mdst[i][j] = 0;
		}	
	}	
	for(int i=1;i<=n;i++)
	{	
		P[i][0] = par[i];
		mdst[i][0] = me[i];
	}	
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(P[i][j-1] != -1)
			{	
				P[i][j] = P[P[i][j-1]][j-1];
				mdst[i][j] = std::max(mdst[i][j-1], mdst[P[i][j-1]][j-1]);
			}		
		}	
	}
	return;	
}

int LCA_find(int p, int q)
{
	int ans = 0;
	if(lvl[p] < lvl[q])
	{
		int tmp = p;
		p = q;
		q = tmp;
	}
	int lx = 0;
	for(lx=1;(1<<lx)<=lvl[p];lx++);
	lx--;
	for(int i=lx;i>=0;i--)
	{
		if((lvl[p] - (1<<i)) >= lvl[q])
		{	
			ans = std::max(ans, mdst[p][i]);
			p = P[p][i];
		}	
	}
	if(p == q)
	return ans;
	for(int i=lx;i>=0;i--)
	{
		if((P[p][i] != -1) && (P[p][i] != P[q][i]))
		{
			ans = std::max(ans, mdst[p][i]);
			ans = std::max(ans, mdst[q][i]);
			p = P[p][i];
			q = P[q][i];
		}	
	}
	ans = std::max(ans, mdst[p][0]);
	ans = std::max(ans, mdst[q][0]);
	return ans;	
}

int main(void)
{
	int n;
	std::cin>>n;
	while(n)
	{
		for(int i=0;i<n-1;i++)
		{
			int s,d,w;
			std::cin>>s>>d>>w;
			G[s].pb(mp(d, w));
			G[d].pb(mp(s, w));
		}	
		dfs_visit(1, -1);
		ST_build(n);
		int q;
		std::cin>>q;
		while(q--)
		{
			int a,b;
			std::cin>>a>>b;
			std::cout<<LCA_find(a, b)<<"\n";
		}
		for(int i=1;i<=n;i++)
		{
			G[i].clear();
			me[i] = 0;
		}
		std::cin>>n;	
	}	
	return 0;
}