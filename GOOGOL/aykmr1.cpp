#include <bits/stdc++.h>
#define CHOR 100001
#define LC 20
#define pb push_back
#define mp std::make_pair

typedef long long ll;

std::vector<std::pair<int, ll> > G[CHOR];
int P[CHOR][LC];
ll dist[CHOR], edist[CHOR], odist[CHOR];
int par[CHOR], lvl[CHOR];

void dfs_visit(int s, int p)
{
	par[s] = p;
	for(int i=0,j=(int)G[s].size();i<j;i++)
	{
		int u = G[s][i].first;
		ll v = G[s][i].second;
		if(p != u)
		{
			dist[u] = v + dist[s];
			lvl[u] = 1 + lvl[s];
			if(v & 1)
			{
				odist[u] = v + odist[s];
				edist[u] = edist[s];
			}
			else
			{
				odist[u] = odist[s];
				edist[u] = v + edist[s];
			}		
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
	int n,m,q;
	std::cin>>n>>m>>q;
	for(int i=0;i<n-1;i++)
	{
		int s, d;
		ll w;
		std::cin>>s>>d>>w;
		G[s].pb(mp(d, w));
		G[d].pb(mp(s, w));
	}	
	dist[1] = 0;
	edist[1] = 0;
	odist[1] = 0;
	lvl[1] = 0;
	dfs_visit(1, -1);
	ST_build(n);
	while(q--)
	{
		int d,s;
		std::cin>>d>>s;
		int lca = LCA_find(s, d);
		ll dx = dist[s] + dist[d] - 2*dist[lca];
		ll edx = edist[s] + edist[d] - 2*edist[lca];
		ll odx = odist[s] + odist[d] - 2*odist[lca];
		if(dx & 1)
		std::cout<<edx<<"\n";
		else std::cout<<odx<<"\n";	
	}
	return 0;
}