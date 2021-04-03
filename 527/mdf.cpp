#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

struct dxz
{
	int par, sze, cen, dia;
}arr[1001];

std::vector<int> G[1001];
std::vector<int> cmx;
bool vis[1001];
int degx[1001];
std::vector<std::pair<int, int> > xd;

class dsu
{
	public: int root(int x);
			void find_union(int x, int y); 
};

int dsu::root(int x)
{
	return (x == arr[x].par) ? x : (arr[x].par = root(arr[x].par));
}

void dsu::find_union(int x, int y)
{
	int rx = root(x);
	int ry = root(y);
	if(rx == ry)
	return;
	if(arr[ry].sze > arr[rx].sze)
	{
		int tmp = ry;
		ry = rx;
		rx = tmp;
	}	
	arr[ry].par = rx;
	arr[rx].sze += arr[ry].sze;
	int dx = 0, dy = 0;
	if(arr[rx].dia & 1)
	dx = arr[rx].dia/2 + 1;
	else dx = arr[rx].dia/2;
	if(arr[ry].dia & 1)
	dy = arr[ry].dia/2 + 1;
	else dy = arr[ry].dia/2;
	if(arr[rx].dia <= dx + dy + 1 && arr[ry].dia <= dx + dy + 1)
	{
		arr[rx].dia = dx + dy + 1;
		if(dy > dx)
		arr[rx].cen = arr[ry].cen;	
	}	
	else if(arr[rx].dia <= arr[ry].dia && arr[ry].dia > dx + dy + 1)
	{
		arr[rx].dia = arr[ry].dia;
		arr[rx].cen = arr[ry].cen;
	}
	return;
}

std::pair<int, int> dfs_visit(int s)
{
	vis[s] = 1;
	cmx.pb(s);
	int g = 0, h1 = 0, h2 = 0;
	for(auto u : G[s])
	{
		if(!vis[u])
		{
			std::pair<int, int> px = dfs_visit(u);
			if(px.second > h1)
			{
				h2 = h1;
				h1 = px.second;
			}
			else if(px.second <= h1 && px.second > h2)
			h2 = px.second;
			g = std::max(g, px.first); 
		}
	}
	g = std::max(g, h1 + h2);
	return mp(g, h1+1);
}

std::pair<int, int> bfs_visit(void)
{
	std::queue<std::pair<int, int> > Q;
	for(int i=0,j=(int)cmx.size();i<j;i++)
	{
		if((degx[cmx[i]] == 1) || (degx[cmx[i]] == 0))
		Q.push(mp(cmx[i], 0));	
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
		for(auto v : G[u])
		{
			degx[v]--;
			degx[u]--;
			if(degx[v] == 1)
			Q.push(mp(v, p.second + 1));	
		}	
	}
	if(!c1)
	{
		int tx = c1;
		c1 = c2;
		c2 = tx;
	}
	return mp(c1, c2);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m;
	std::cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		arr[i].par = i;
		arr[i].sze = 1;
		arr[i].dia = 0;
		arr[i].cen = i;
	}	
	dsu T;
	for(int i=0;i<m;i++)
	{
		int s,d;
		std::cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
		T.find_union(s, d);
		degx[s]++;
		degx[d]++;
	}	
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			cmx.clear();
			int dia = dfs_visit(i).first;
			int cen = bfs_visit().first;
			arr[T.root(i)].dia = dia;
			arr[T.root(i)].cen = cen;
		}
	}
	std::set<std::pair<int, int> > Z;
	for(int i=1;i<=n;i++)
	Z.insert(mp(-arr[T.root(i)].dia, T.root(i)));
	while((int)Z.size() > 1)
	{
		std::pair<int, int> x = *Z.begin();
		Z.erase(Z.begin());
		std::pair<int, int> y = *Z.begin();
		Z.erase(Z.begin());
		xd.pb(mp(arr[x.second].cen, arr[y.second].cen));
		T.find_union(x.second, y.second);
		Z.insert(mp(-arr[T.root(x.second)].dia, T.root(x.second)));
	}	
	int x = (*Z.begin()).second;
	std::cout<<arr[x].dia<<"\n";
	for(int i=0,j=(int)xd.size();i<j;i++)
	std::cout<<xd[i].first<<" "<<xd[i].second<<"\n";
	return 0;
}