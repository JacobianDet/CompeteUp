#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair
#define CHOR 150000

std::vector<int> G[CHOR];
std::vector<int> T[CHOR];
int atk[CHOR], degx[CHOR], lvl[CHOR];
bool mark[CHOR];

struct motu
{
	int tl, dia, ht;
};

bool dfs_vis1(int s, int p)
{
	for(auto u : G[s])
	{
		if(u != p)
		mark[s] |= dfs_vis1(u, s);
	}
	for(auto u : G[s])
	{
		if(u != p)
		{
			if(mark[s] && mark[u])
			{
				T[s].pb(u);
				T[u].pb(s);
				degx[s]++;
				degx[u]++;
			}	
		}
	}
	return mark[s];
}

motu dfs_vis2(int s, int p)
{
	motu ov = {0, 0, 0};
	int g = 0, h1 = 0, h2 = 0;
	for(auto u : G[s])
	{
		if(u != p)
		{
			motu z = dfs_vis2(u, s);
			if(mark[u])
			{
				if(z.ht > h1)
				{
					h2 = h1;
					h1 = z.ht;
				}	
				else if(z.ht <= h1 && z.ht > h2)
				h2 = z.ht;
				g = std::max(g, z.dia);	
				ov.tl += (2 + z.tl);
			}
		}
	}
	if(mark[s])
	{
		g = std::max(g, h1 + h2);
		h1++;
		ov.dia = g;
		ov.ht = h1;
		return ov;
	}	
	else return ov;
}

std::pair<int, int> bfs_visit(int n)
{
	std::queue<std::pair<int, int> > Q;
	for(int i=1;i<=n;i++)
	{
		if(degx[i] == 1)
		Q.push(mp(i, 0));	
	}	
	int c1 = 0, c2 = 0, mln1 = 0, mln2 = 0;
	while(!Q.empty())
	{
		std::pair<int, int> p = Q.front();
		Q.pop();
		int u = p.first;
		if(p.second > mln1)
		{
			c2 = c1;
			c1 = u;
			mln2 = mln1;
			mln1 = p.second;
		} 
		else if(p.second <= mln1 && p.second >= mln2)
		{	
			mln2 = p.second;
			c2 = u;
		}	
		for(auto v : T[u])
		{
			degx[v]--;
			degx[u]--;
			if(degx[v] == 1)
			Q.push(mp(v, p.second + 1));	
		}	
	}
	return mp(c1, c2);
}

void dfs_vis3(int s, int p)
{
	if(p != -1)
	lvl[s] = 1 + lvl[p];
	for(auto u : T[s])
	{
		if(u != p)
		dfs_vis3(u, s);	
	}	
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m;
	std::cin>>n>>m;
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		std::cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}
	for(int i=1;i<=m;i++)
	{
		std::cin>>atk[i];
		mark[atk[i]] = 1;
	}
	mark[atk[1]] |= dfs_vis1(atk[1], -1);
	motu z = dfs_vis2(atk[1], -1);
	std::pair<int, int> px = bfs_visit(n);
	lvl[px.first] = 0;
	dfs_vis3(px.first, -1);
	int mdist = 0, mnd = CHOR;
	for(int i=1;i<=m;i++)
	{
		if(mdist < lvl[atk[i]])
		{
			mdist = lvl[atk[i]];
			mnd = atk[i];
		}	
		else if(mdist == lvl[atk[i]])
		mnd = std::min(mnd, atk[i]);	
	}	
	if(px.second)
	{
		lvl[px.second] = 0;
		dfs_vis3(px.second, -1);
		mdist = 0;
		int mnd2 = CHOR;
		for(int i=1;i<=m;i++)
		{
			if(mdist < lvl[atk[i]])
			{
				mdist = lvl[atk[i]];
				mnd2 = atk[i];
			}	
			else if(mdist == lvl[atk[i]])
			mnd2 = std::min(mnd2, atk[i]);	
		}	
		mnd = std::min(mnd, mnd2);
	}	
	std::cout<<mnd<<"\n"<<(z.tl - z.dia)<<"\n";
	return 0;
}