#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

std::vector<int> G[1001];
std::vector<int> G2[1001];
std::pair<int, int> E[1001];
bool vis[1001];
int par[1001], lvl[1001], cord[1001], cc[1001], dist[1001];
int nd;

bool dfs_cyc(int s, int p)
{
	bool ok = 1;
	vis[s] = 1;
	if(p != -1)
	par[s] = p;	
	for(int i=0,j=(int)G[s].size();i<j;i++)
	{
		if(!vis[G[s][i]])
		ok &= dfs_cyc(G[s][i], s);
		else
		{
			if(G[s][i] == p)
			continue;
			else
			{
				ok = 0;
				par[G[s][i]] = s;
				nd = s;
			}	
		}
		if(!ok)
		break;	
	}	
	return ok;
}

void dfs_visit(int s, int p)
{
	if(p != -1)
	{
		par[s] = p;
		lvl[s] = 1 + lvl[p];
	}
	for(int i=0,j=(int)G2[s].size();i<j;i++)
	{
		if(G2[s][i] != p)
		dfs_visit(G2[s][i], s);	
	}	
	return;
}

int main(void)
{
	//freopen("input.in","r",stdin);
	//freopen("output.txt","w",stdout);
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		nd = 0;
		int n;
		std::cin>>n;
		for(int i=1;i<=n;i++)
		dist[i] = 1001;
		for(int i=0;i<n;i++)
		{
			int s,d;
			std::cin>>s>>d;
			E[i] = mp(s, d);
			G[s].pb(d);
			G[d].pb(s);
		}	
		bool ok = dfs_cyc(1, -1);
		int x = nd;
		while(par[x] != nd)
		{
			cord[x] = 1;
			dist[x] = 0;
			x = par[x];
		}
		cord[x] = 1;
		dist[x] = 0;
		x = 1;	
		par[1] = 0;
		lvl[1] = 0;
		for(int i=0;i<n;i++)
		{
			int s = E[i].first;
			int d = E[i].second;
			if(!cord[s])
			{	
				x++;
				cc[x] = s;
				cord[s] = x;
			}	
			if(!cord[d])
			{
				x++;
				cc[x] = d;
				cord[d] = x;
			}	
			s = cord[s];
			d = cord[d];
			if((s == d) || (find(G2[s].begin(), G2[s].end(), d) != G2[s].end()))
			continue;
			else
			{
				G2[s].pb(d);
				G2[d].pb(s);
			}	
		}
		dfs_visit(1, -1);
		for(int i=2;i<=x;i++)
		dist[cc[i]] = lvl[i];
		std::cout<<"Case #"<<t<<": "; 
		for(int i=1;i<=n;i++)
		std::cout<<dist[i]<<" ";
		std::cout<<"\n";
		for(int i=1;i<=n;i++)
		{
			G[i].clear();
			G2[i].clear();
			vis[i] = 0;
			cord[i] = 0;
			cc[i] = 0;
			lvl[i] = 0;
			par[i] = 0;
		}	
	}	
	return 0;
}