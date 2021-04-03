#include <bits/stdc++.h>
#define CHOR 100001
#define pb push_back
#define mp std::make_pair

std::vector<int> G[CHOR];
std::pair<int, int> E[CHOR];
bool vis[CHOR];
int lvl[CHOR], heff[CHOR], arr[CHOR], sze[CHOR], par[CHOR], cord[CHOR];
int P[CHOR][20];

//SOURCE CODE BY AminAnvari

class dsu
{
	public: int root(int x);
			void find_union(int x, int y);
};

int dsu::root(int x)
{
	return ((arr[x] == x) ? x : (arr[x] = root(arr[x])));
}

void dsu::find_union(int x, int y)
{
	int rx = root(x);
	int ry = root(y);
	if(rx == ry)
	return;
	if(sze[ry] > sze[rx])
	{
		int tmp = rx;
		rx = ry;
		ry = tmp;
	}	
	sze[rx] += sze[ry];
	arr[ry] = rx;
	return;
}

void dfs_cyc(int s, int p)
{
	vis[s] = 1;
	heff[s] = lvl[s];
	dsu T;
	for(int i=0,j=(int)G[s].size();i<j;i++)
	{
		int u = G[s][i];
		if(!vis[u])
		{
			lvl[u] = 1 + lvl[s];
			dfs_cyc(u, s);
			if(heff[u] < lvl[u])
			T.find_union(s, u);
			heff[s] = std::min(heff[s], heff[u]);
		}	
		else if(u != p)
		heff[s] = std::min(heff[s], lvl[u]);	
	}
	return;	
}

void dfs_vis(int s, int p)
{
	if(p != -1)
	{
		lvl[s] = 1 + lvl[p];
		par[s] = p;
	}	
	for(int i=0,j=(int)G[s].size();i<j;i++)
	{
		if(G[s][i] != p)
		dfs_vis(G[s][i], s);	
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
	int lx = 0;
	for(lx=1;(1<<lx)<=lvl[p];lx++);
	lx--;
	for(int i=lx;i>=0;i--)
	{
		if((lvl[p] - (1<<i)) >= lvl[q])
		p = P[p][i];	
	}	
	if(p == q)
	return p;
	for(int i=lx;i>=0;i--)
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
	int n,m;
	std::cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int s,d;
		std::cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
		E[i] = mp(s, d);
	}	
	for(int i=1;i<=n;i++)
	{
		arr[i] = i;
		sze[i] = 1;
	}	
	dfs_cyc(1, -1);
	for(int i=1;i<=n;i++)
	G[i].clear();
	dsu T;
	memset(lvl, 0, sizeof(lvl));
	int x = 0;
	for(int i=0;i<m;i++)
	{
		int s = E[i].first;
		int d = E[i].second;
		s = T.root(s);
		d = T.root(d);
		if(!cord[s])
		{
			x++;
			cord[s] = x;
		}	
		if(!cord[d])
		{
			x++;
			cord[d] = x;
		}
		s = cord[s];
		d = cord[d];	
		if(s != d)
		{
			G[s].pb(d);
			G[d].pb(s);
		}	
	}
	dfs_vis(1, -1);
	ST_build(x);
	int q;
	std::cin>>q;
	while(q--)
	{
		int l,r;
		std::cin>>l>>r;
		l = cord[T.root(l)];
		r = cord[T.root(r)];
		int lca = LCA_find(l, r);
		std::cout<<lvl[l]+lvl[r]-2*lvl[lca]<<"\n";
	}	
	return 0;
}